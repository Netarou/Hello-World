/*  test.h   */
#ifndef _TEST_HEADER_
#define _TEST_HEADER_
 
typedef struct Interface
{
    void (*PrintData)(struct Interface*);
}Interface;
 
/*  生成関数と破棄関数    */
Interface* CreateInterface( int, int );/* 引数付きコンストラクタのイメージ  */
void ReleaseInterface( struct Interface* );

#endif /*   _TEST_EADER  */
 
/*  ここまで    */