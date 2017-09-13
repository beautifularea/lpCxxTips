delete itself -- the keyword -- will not throw. But there is nothing in the language that prevents destructors from throwing (though it is a bad idea), which means technically speaking, it is 
possible for delete foo; to throw if foo's destructor or something it calls can throw.

However, a good rule of thumb is never let exceptions leak from a destructor.

#define  SafeDelete(pData) { try { delete pData; } catch (...) { ASSERT(FALSE); } pData=NULL; } 
