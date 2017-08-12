# Constant
Cxx supports two notions of immutability:
* const : meaning 'I promise not to change this value',The compiler enforces the promise made by const.
* constexpr: meaning 'to be evaluated at compile time'

To be constexpr, a function must be rather simple: just a return-statement computing a value.
