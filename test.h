/*  test.h   */
#ifndef _TEST_HEADER_
#define _TEST_HEADER_
 
typedef struct Interface
{
    void (*PrintData)(struct Interface*);
}Interface;
 
/*  �����֐��Ɣj���֐�    */
Interface* CreateInterface( int, int );/* �����t���R���X�g���N�^�̃C���[�W  */
void ReleaseInterface( struct Interface* );

#endif /*   _TEST_EADER  */
 
/*  �����܂�    */