#pragma once
#ifndef _TYPE_
#define _TYPE_

#define _DSCPP_BEGIN namespace dscpp {
#define _DSCPP_END  }
#define SIZE size_t
#define CAPACITY size_t
#define INDEX_ERROR -1
#define CHECK_INDEX(a,b) \
((a < b && a > 0) ? 1 : -1)



#endif // !_TYPE_
