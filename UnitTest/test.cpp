//============================================================
//
//  title  : GoogleTest�蓮�e�X�g�R�[�h [Manualtest.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/11
//  Update : 2021/10/13
//
//============================================================
//#include "gtest/gtest.h"
//#include <gtest/gtest.h>
//#include "../DoublyLinkedList/doublyLinkedList.h"
#include "pch.h"


//namespace ex01_DataStructure
//{
//	namespace chapter2
//	{
//		
//	}
//}


//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------
/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA���X�g����ł���ꍇ�̖߂�l�̃e�X�g
	@details	ID:���X�g-0(�蓮)\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_GET_DATA_NUM_IS_NULL�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(GetDataCountTest, TestGetDataNum)
{
#if defined TT_TEST_GET_DATA_NUM_IS_NULL
	DoublyLinkedList list;
	EXPECT_EQ(0, list.GetDataCount());
#endif //TT_TEST_GET_DATA_NUM_IS_NULL
	SUCCEED();
}


/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA���X�g�����ւ̑}�����s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-1(�蓮)\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_LIST_END_INSERT_RETURN_1�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(ListEndInsertReturn1Test, TestGetDataNum)
{
#if defined TT_TEST_LIST_END_INSERT_RETURN_1
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	list.Insert(it);
	EXPECT_EQ(1, list.GetDataCount());
#endif //TT_TEST_LIST_END_INSERT_RETURN_1
	SUCCEED();
}


/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA���X�g�����ւ̑}�������s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-2(�蓮)\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_LIST_END_INSERT_RETURN_0�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(ListEndInsertReturn0Test, TestGetDataNum)
{
#if defined TT_TEST_LIST_END_INSERT_RETURN_0
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it;
	list.Insert(it);
	EXPECT_EQ(0, list.GetDataCount());
#endif //TT_TEST_LIST_END_INSERT_RETURN_0
	SUCCEED();
}


/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA�f�[�^�̑}�����s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-3(�蓮)\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_DATA_END_INSERT_RETURN_1�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
//TEST(ListEndInsertReturn0Test, TestGetDataNum)
//{
//#if defined TT_TEST_DATA_END_INSERT_RETURN_1
//	DoublyLinkedList list;
//	DoublyLinkedList::Iterator it;
//	list.Insert(it);
//	EXPECT_EQ(0, list.GetDataCount());
//#endif //TT_TEST_DATA_END_INSERT_RETURN_1
//	SUCCEED();
//}