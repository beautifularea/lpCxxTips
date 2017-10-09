/**
  从一个QQ群找到的，用来学习下无锁的Stack实现。
*/

struct NodeHeader {
	NodeHeader *next;
};

struct alignas(alignof(void *) * 2) Stack {
	NodeHeader *last;
	NodeHeader *first;
};

void push(Stack volatile *__restrict__ stack, NodeHeader *__restrict__ node) noexcept {
	Stack q_ch[1], q_st[1];

	__atomic_load(q_ch, stack, __ATOMIC_ACQUIRE);
	do {
		q_st->last  = q_ch->last;
		q_st->first = node;
		node->next  = q_ch->first;
	} while(!__atomic_compare_exchange(stack, q_ch, q_st, false, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE));
}

NodeHeader *pop_unique(Stack volatile *__restrict__ stack) noexcept {
	NodeHeader *node;
	Stack q_ch[1], q_st[1];

	__atomic_load(q_ch, stack, __ATOMIC_ACQUIRE);
	do {
		node = q_ch->first;
		if(!node){
			return 0;
		}
		q_st->last  = node->next ? q_ch->last : 0;
		q_st->first = node->next;
	} while(!__atomic_compare_exchange(stack, q_ch, q_st, false, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE));

	return node;
}
NodeHeader *pop_multiple(Stack volatile *__restrict__ stack) noexcept {
	NodeHeader *node;
	Stack q_ex[1], q_ch[1], q_st[1];

	// Detach all nodes. `*stack` is empty hereafter.
	q_st->last  = 0;
	q_st->first = 0;
	__atomic_exchange(stack, q_st, q_ex, __ATOMIC_ACQ_REL);
	node = q_ex->first;
	if(!node){
		return 0;
	}
	if(!node->next){
		return node;
	}

	// Re-attach nodes remaining into the front of `*stack`.
	__atomic_load(q_ch, stack, __ATOMIC_ACQUIRE);
	do {
		q_st->last  = q_ch->last;
		q_st->first = node->next;
		q_ex->last->next = q_ch->first;
	} while(!__atomic_compare_exchange(stack, q_ch, q_st, false, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE));

	return node;
}
