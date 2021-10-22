//============================================================
//
//  title  : �o�������X�g�̎����e�X�g�R�[�h [outoListTest.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/11
//  Update : 2021/10/22
//
//============================================================
#include "gtest/gtest.h"
#include "../DoublyLinkedList/doublyLinkedList.h"


//--------------------------------------------------------------------------------
// �R���p�C���֘A�����e�X�g
//--------------------------------------------------------------------------------

//=================================== �f�[�^���̎擾 ===================================
/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA���X�g����ł���ꍇ�̖߂�l�̃e�X�g
	@details	ID:���X�g-0\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, GetDataCountTest)
{
	DoublyLinkedList list;
	EXPECT_EQ(0, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA���X�g�����ւ̑}�����s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-1\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����1�����Ă���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, ListEndInsertReturn1Test)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetEndIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));
	EXPECT_EQ(1, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA���X�g�����ւ̑}�������s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-2\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, ListEndInsertReturn0Test)
{
	// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
	//DoublyLinkedList list;
	//DoublyLinkedList::Iterator it = list.GetEndIterator();
	//ASSERT_FALSE(list.Insert(it, 1));
	//EXPECT_EQ(0, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA�f�[�^�̑}�����s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-3\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����1�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndInsertReturn1Test)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	EXPECT_EQ(1, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-4\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndInsertReturn0Test)
{
	// ���s���̂��߂����ł̓X�L�b�v
	//DoublyLinkedList list;
	//DoublyLinkedList::Iterator it = list.GetTopIterator();
	//ASSERT_TRUE(list.Insert(it, 1));
	//EXPECT_EQ(0, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA�f�[�^�̍폜���s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-5\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndRemoveReturn0Test)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));
	ASSERT_TRUE(list.Remove(it));
	EXPECT_EQ(0, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA�f�[�^�̍폜�����s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-6\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̍폜�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndRemoveReturn1Test)
{
	// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
	//DoublyLinkedList list;
	//DoublyLinkedList::Iterator it = list.GetTopIterator();
	//ASSERT_TRUE(list.Insert(it, 1));
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(1, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āA���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l�̃e�X�g
	@details	ID:���X�g-7\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndRemoveReturn0WhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_FALSE(list.Remove(it));
	EXPECT_EQ(0, list.GetDataCount());
}




//=================================== �f�[�^�̑}�� ===================================

/**********************************************************************************//**
	@brief		�f�[�^�̑}���@�\�ɂ��āA���X�g����ł���ꍇ�ɁA�}�������ۂ̋����̃e�X�g
	@details	ID:���X�g-9\n
				�f�[�^�̑}���@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�}�������ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� true �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestInsertData, DataInsertWhenListIsEmpty)
{
	DoublyLinkedList list;

	// �擪�Ɩ����̃C�e���[�^���ꂼ����m�F
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	//DoublyLinkedList::Iterator it = list.GetEndIterator();

	EXPECT_EQ(true, list.Insert(it, 1, "a"));
}

/**********************************************************************************//**
	@brief		�f�[�^�̑}���@�\�ɂ��āA���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋����̃e�X�g
	@details	ID:���X�g-10\n
				�f�[�^�̑}���@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� true �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestInsertData, TopDataInsertWhenListIsNoEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	EXPECT_EQ(true, list.Insert(it3, 3, "ccc"));
}

/**********************************************************************************//**
	@brief		�f�[�^�̑}���@�\�ɂ��āA���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋����̃e�X�g
	@details	ID:���X�g-11\n
				�f�[�^�̑}���@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� true �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestInsertData, EndDataInsertWhenListIsNoEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "b"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	EXPECT_EQ(true, list.Insert(it3, 3, "ccc"));
}

/**********************************************************************************//**
	@brief		�f�[�^�̑}���@�\�ɂ��āA���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋����̃e�X�g
	@details	ID:���X�g-12\n
				�f�[�^�̑}���@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� true �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestInsertData, DataInsertWhenListIsNoEmpty)
{
	// �f�[�^��2�}������3�ڂ̃f�[�^�Ō���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	
	// �擪�Ɩ����ƒ����̃C�e���[�^�ł��ꂼ��m�F����
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	//DoublyLinkedList::Iterator it3 = list.GetEndIterator();
	//DoublyLinkedList::Iterator it3 = ++list.GetTopIterator();
	EXPECT_EQ(true, list.Insert(it3, 3, "ccc"));
}

/**********************************************************************************//**
	@brief		�f�[�^�̑}���@�\�ɂ��āAConstIterator���w�肵�đ}�����s�����ۂ̋����̃e�X�g
	@details	ID:���X�g-13\n
				�f�[�^�̑}���@�\�̃e�X�g�ł��B\n
				ConstIterator���w�肵�đ}�����s�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� true �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestInsertData, ConstIteratorDataInsert)
{
	// �f�[�^��2�}������3�ڂ̃f�[�^�Ō���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// �擪�Ɩ����ƒ����̃C�e���[�^�ł��ꂼ��m�F����
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	//DoublyLinkedList::ConstIterator it3 = list.GetEndConstIterator();
	//DoublyLinkedList::ConstIterator it3 = ++list.GetTopConstIterator();
	EXPECT_EQ(true, list.Insert(it3, 3, "ccc"));
}

/**********************************************************************************//**
	@brief		�f�[�^�̑}���@�\�ɂ��āA�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋����̃e�X�g
	@details	ID:���X�g-14\n
				�f�[�^�̑}���@�\�̃e�X�g�ł��B\n
				�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋������m�F���Ă��܂��B\n
				�߂�l�� false �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestInsertData, NotIteratorDataInsert)
{
	// �f�[�^��2�}������3�ڂ̃f�[�^�Ō���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// ���X�g���Q�Ƃ��Ȃ��C�e���[�^�������ɂ����
	DoublyLinkedList::Iterator it3;
	EXPECT_EQ(false, list.Insert(it3, 3, "ccc"));
}




//=================================== �f�[�^�̍폜 ===================================

/**********************************************************************************//**
	@brief		�f�[�^�̍폜�@�\�ɂ��āA���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋����̃e�X�g
	@details	ID:���X�g-16\n
				�f�[�^�̍폜�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� false �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestRemoveData, DataRemoveWhenListIsEmpty)
{
	DoublyLinkedList list;

	// �擪�Ɩ����̃C�e���[�^�ł��ꂼ��m�F����
	//DoublyLinkedList::Iterator it = list.GetTopIterator();
	DoublyLinkedList::Iterator it = list.GetEndIterator();

	EXPECT_EQ(false, list.Remove(it));
}

/**********************************************************************************//**
	@brief		�f�[�^�̍폜�@�\�ɂ��āA���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋����̃e�X�g
	@details	ID:���X�g-17\n
				�f�[�^�̍폜�@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� true �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestRemoveData, TopDataRemoveWhenListIsNoEmpty)
{
	// �f�[�^��3�}������3�ڂ̃f�[�^�Ō���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::Iterator it = list.GetTopIterator();
	EXPECT_EQ(true, list.Remove(it));
}

/**********************************************************************************//**
	@brief		�f�[�^�̍폜�@�\�ɂ��āA���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋����̃e�X�g
	@details	ID:���X�g-18\n
				�f�[�^�̍폜�@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� false �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestRemoveData, EndDataRemoveWhenListIsNoEmpty)
{
	// �f�[�^��3�}������3�ڂ̃f�[�^�Ō���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::Iterator it = list.GetEndIterator();
	EXPECT_EQ(false, list.Remove(it));
}

/**********************************************************************************//**
	@brief		�f�[�^�̍폜�@�\�ɂ��āA���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋����̃e�X�g
	@details	ID:���X�g-19\n
				�f�[�^�̍폜�@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� true �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestRemoveData, DataRemoveWhenListIsNoEmpty)
{
	// �f�[�^��3�}������3�ڂ̃f�[�^�Ō���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::Iterator it = ++list.GetTopIterator();
	EXPECT_EQ(true, list.Remove(it));
}

/**********************************************************************************//**
	@brief		�f�[�^�̍폜�@�\�ɂ��āAConstIterator���w�肵�č폜���s�����ۂ̋����̃e�X�g
	@details	ID:���X�g-20\n
				�f�[�^�̍폜�@�\�̃e�X�g�ł��B\n
				ConstIterator���w�肵�č폜���s�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�� true �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestRemoveData, ConstIteratorDataRemove)
{
	// �f�[�^��3�}������3�ڂ̃f�[�^�Ō���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	EXPECT_EQ(true, list.Remove(it));
}

/**********************************************************************************//**
	@brief		�f�[�^�̍폜�@�\�ɂ��āA�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋����̃e�X�g
	@details	ID:���X�g-21\n
				�f�[�^�̍폜�@�\�̃e�X�g�ł��B\n
				�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋������m�F���Ă��܂��B\n
				�߂�l�� false �ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestRemoveData, NotIteratorDataRemove)
{
	// �f�[�^��3�}������3�ڂ̃f�[�^�Ō���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::Iterator it;
	EXPECT_EQ(false, list.Remove(it));
}




//=============================== �擪�C�e���[�^�̎擾 ===================================

/**********************************************************************************//**
	@brief		�擪�C�e���[�^�̎擾�@�\�ɂ��āA���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-23\n
				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�������C�e���[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenListIsEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator topIt = list.GetTopIterator();
	DoublyLinkedList::Iterator endIt = list.GetEndIterator();

	// �擪�Ɩ����̃C�e���[�^���w���v�f����v���邱�Ƃ��m�F
	EXPECT_EQ(topIt.GetData().score, endIt.GetData().score);
	EXPECT_EQ(topIt.GetData().userName, endIt.GetData().userName);
}

/**********************************************************************************//**
	@brief		�擪�C�e���[�^�̎擾�@�\�ɂ��āA���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-24\n
				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃C�e���[�^�̃f�[�^���p�ӂ����f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenListIsOneData)
{
	// �f�[�^����p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));

	// �p�ӂ����f�[�^�ƈ�v���邩���m�F
	EXPECT_EQ(1, list.GetTopIterator().GetData().score);
	EXPECT_EQ("a", list.GetTopIterator().GetData().userName);
}

/**********************************************************************************//**
	@brief		�擪�C�e���[�^�̎擾�@�\�ɂ��āA���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-25\n
				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃C�e���[�^�̃f�[�^���p�ӂ�����ڂ̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenListIsTwoData)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// �p�ӂ����f�[�^�ƈ�v���邩���m�F
	EXPECT_EQ(2, list.GetTopIterator().GetData().score);
	EXPECT_EQ("bb", list.GetTopIterator().GetData().userName);
}

/**********************************************************************************//**
	@brief		�擪�C�e���[�^�̎擾�@�\�ɂ��āA�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-26\n
				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃C�e���[�^�̃f�[�^���擪�̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenDataInsert)
{
	// �f�[�^���O�p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// �f�[�^��}��
	// �擪�Ɩ����ƒ����̃C�e���[�^�ł��ꂼ��m�F����

	// �擪�ɑ}�����s�����ꍇ�̊m�F
	DoublyLinkedList::Iterator it4 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	EXPECT_EQ(4, list.GetTopIterator().GetData().score);
	EXPECT_EQ("dddd", list.GetTopIterator().GetData().userName);

	// �����ɑ}�����s�����ꍇ�̊m�F
	//DoublyLinkedList::Iterator it4 = ++list.GetTopIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//EXPECT_EQ(3, list.GetTopIterator().GetData().score);
	//EXPECT_EQ("ccc", list.GetTopIterator().GetData().userName);

	// �����ɑ}�����s�����ꍇ�̊m�F
	//DoublyLinkedList::Iterator it4 = list.GetEndIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//EXPECT_EQ(3, list.GetTopIterator().GetData().score);
	//EXPECT_EQ("ccc", list.GetTopIterator().GetData().userName);
}

/**********************************************************************************//**
	@brief		�擪�C�e���[�^�̎擾�@�\�ɂ��āA�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-27\n
				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃C�e���[�^�̃f�[�^���擪�̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenDataRemove)
{
	// �f�[�^���O�p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// �f�[�^���폜
	// �擪�Ɩ����ƒ����̃C�e���[�^�ł��ꂼ��m�F����

	// �擪�̍폜���s�����ꍇ�̊m�F
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Remove(it));
	EXPECT_EQ(2, list.GetTopIterator().GetData().score);
	EXPECT_EQ("bb", list.GetTopIterator().GetData().userName);

	// �����̍폜���s�����ꍇ�̊m�F
	//DoublyLinkedList::Iterator it = ++list.GetTopIterator();
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(3, list.GetTopIterator().GetData().score);
	//EXPECT_EQ("ccc", list.GetTopIterator().GetData().userName);

	// �����̍폜���s�����ꍇ�̊m�F
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(3, list.GetTopIterator().GetData().score);
	//EXPECT_EQ("ccc", list.GetTopIterator().GetData().userName);
}




//========================= �擪�R���X�g�C�e���[�^�̎擾 ===================================

/**********************************************************************************//**
	@brief		�擪�R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-29\n
				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�������R���X�g�C�e���[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenListIsEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator topIt = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator endIt = list.GetEndConstIterator();

	// �擪�Ɩ����̃R���X�g�C�e���[�^���w���v�f����v���邱�Ƃ��m�F
	EXPECT_EQ(topIt.GetConstData().score, endIt.GetConstData().score);
	EXPECT_EQ(topIt.GetConstData().userName, endIt.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�擪�R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-30\n
				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃R���X�g�C�e���[�^�̃f�[�^���p�ӂ����f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenListIsOneData)
{
	// �f�[�^����p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));

	// �p�ӂ����f�[�^�ƈ�v���邩���m�F
	EXPECT_EQ(1, list.GetTopConstIterator().GetConstData().score);
	EXPECT_EQ("a", list.GetTopConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�擪�R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-31\n
				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃R���X�g�C�e���[�^�̃f�[�^���p�ӂ�����ڂ̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenListIsTwoData)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// �p�ӂ����f�[�^�ƈ�v���邩���m�F
	EXPECT_EQ(2, list.GetTopConstIterator().GetConstData().score);
	EXPECT_EQ("bb", list.GetTopConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�擪�R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-32\n
				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃R���X�g�C�e���[�^�̃f�[�^���擪�̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenDataInsert)
{
	// �f�[�^���O�p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// �f�[�^��}��
	// �擪�Ɩ����ƒ����̃R���X�g�C�e���[�^�ł��ꂼ��m�F����

	// �擪�ɑ}�����s�����ꍇ�̊m�F
	DoublyLinkedList::ConstIterator it4 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	EXPECT_EQ(4, list.GetTopConstIterator().GetConstData().score);
	EXPECT_EQ("dddd", list.GetTopConstIterator().GetConstData().userName);

	// �����ɑ}�����s�����ꍇ�̊m�F
	//DoublyLinkedList::ConstIterator it4 = ++list.GetTopConstIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//EXPECT_EQ(3, list.GetTopConstIterator().GetConstData().score);
	//EXPECT_EQ("ccc", list.GetTopConstIterator().GetConstData().userName);

	// �����ɑ}�����s�����ꍇ�̊m�F
	//DoublyLinkedList::ConstIterator it4 = list.GetEndConstIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//EXPECT_EQ(3, list.GetTopConstIterator().GetConstData().score);
	//EXPECT_EQ("ccc", list.GetTopConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�擪�R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-33\n
				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃R���X�g�C�e���[�^�̃f�[�^���擪�̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenDataRemove)
{
	// �f�[�^���O�p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// �f�[�^���폜
	// �擪�Ɩ����ƒ����̃R���X�g�C�e���[�^�ł��ꂼ��m�F����

	// �擪�̍폜���s�����ꍇ�̊m�F
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	ASSERT_TRUE(list.Remove(it));
	EXPECT_EQ(2, list.GetTopConstIterator().GetConstData().score);
	EXPECT_EQ("bb", list.GetTopConstIterator().GetConstData().userName);

	// �����̍폜���s�����ꍇ�̊m�F
	//DoublyLinkedList::ConstIterator it = ++list.GetTopConstIterator();
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(3, list.GetTopConstIterator().GetConstData().score);
	//EXPECT_EQ("ccc", list.GetTopConstIterator().GetConstData().userName);

	// �����̍폜���s�����ꍇ�̊m�F
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(3, list.GetTopConstIterator().GetConstData().score);
	//EXPECT_EQ("ccc", list.GetTopConstIterator().GetConstData().userName);
}




//============================== �����C�e���[�^�̎擾 ===================================

/**********************************************************************************//**
	@brief		�����C�e���[�^�̎擾�@�\�ɂ��āA���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-35\n
				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l���擪�C�e���[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenListIsEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator topIt = list.GetTopIterator();
	DoublyLinkedList::Iterator endIt = list.GetEndIterator();

	// �擪�Ɩ����̃C�e���[�^���w���v�f����v���邱�Ƃ��m�F
	EXPECT_EQ(endIt.GetData().score, topIt.GetData().score);
	EXPECT_EQ(endIt.GetData().userName, topIt.GetData().userName);
}

/**********************************************************************************//**
	@brief		�����C�e���[�^�̎擾�@�\�ɂ��āA���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-36\n
				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃C�e���[�^�̈�O�̃f�[�^���p�ӂ����f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenListIsOneData)
{
	// �f�[�^����p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetEndIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// �p�ӂ����f�[�^�ƈ�v���邩���m�F
	DoublyLinkedList::Iterator it = --list.GetEndIterator();
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		�����C�e���[�^�̎擾�@�\�ɂ��āA���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-37\n
				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃C�e���[�^�̈�O�̃f�[�^���p�ӂ�����ڂ̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenListIsTwoData)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// �p�ӂ����f�[�^�ƈ�v���邩���m�F
	DoublyLinkedList::Iterator it = --list.GetEndIterator();
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		�����C�e���[�^�̎擾�@�\�ɂ��āA�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-38\n
				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃C�e���[�^�̈�O�̃f�[�^���擪�̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenDataInsert)
{
	// �f�[�^���O�p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// �f�[�^��}��
	// �擪�Ɩ����ƒ����̃C�e���[�^�ł��ꂼ��m�F����

	// �擪�ɑ}�����s�����ꍇ�̊m�F
	DoublyLinkedList::Iterator it4 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	DoublyLinkedList::Iterator it = --list.GetEndIterator();
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// �����ɑ}�����s�����ꍇ�̊m�F
	//DoublyLinkedList::Iterator it4 = ++list.GetTopIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//EXPECT_EQ(1, it.GetData().score);
	//EXPECT_EQ("a", it.GetData().userName);

	// �����ɑ}�����s�����ꍇ�̊m�F
	//DoublyLinkedList::Iterator it4 = list.GetEndIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//EXPECT_EQ(4, it.GetData().score);
	//EXPECT_EQ("dddd", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		�����C�e���[�^�̎擾�@�\�ɂ��āA�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-39\n
				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃C�e���[�^�̃f�[�^���擪�̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenDataRemove)
{
	// �f�[�^���O�p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// �f�[�^���폜
	// �擪�Ɩ����ƒ����̃C�e���[�^�ł��ꂼ��m�F����

	// �擪�̍폜���s�����ꍇ�̊m�F
	DoublyLinkedList::Iterator removeIt = list.GetTopIterator();
	ASSERT_TRUE(list.Remove(removeIt));
	DoublyLinkedList::Iterator it = --list.GetEndIterator();
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// �����̍폜���s�����ꍇ�̊m�F
	//DoublyLinkedList::Iterator removeIt = ++list.GetTopIterator();
	//ASSERT_TRUE(list.Remove(removeIt));
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//EXPECT_EQ(1, it.GetData().score);
	//EXPECT_EQ("a", it.GetData().userName);

	// �����̍폜���s�����ꍇ�̊m�F
	//DoublyLinkedList::Iterator removeIt = --list.GetEndIterator();
	//ASSERT_TRUE(list.Remove(removeIt));
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//EXPECT_EQ(2, it.GetData().score);
	//EXPECT_EQ("bb", it.GetData().userName);
}




//========================= �����R���X�g�C�e���[�^�̎擾 ===================================

/**********************************************************************************//**
	@brief		�����R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-41\n
				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l���擪�R���X�g�C�e���[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenListIsEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator topIt = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator endIt = list.GetEndConstIterator();

	// �擪�Ɩ����̃R���X�g�C�e���[�^���w���v�f����v���邱�Ƃ��m�F
	EXPECT_EQ(endIt.GetConstData().score, topIt.GetConstData().score);
	EXPECT_EQ(endIt.GetConstData().userName, topIt.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�����R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-42\n
				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃R���X�g�C�e���[�^�̈�O�̃f�[�^���p�ӂ����f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenListIsOneData)
{
	// �f�[�^����p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetEndConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// �p�ӂ����f�[�^�ƈ�v���邩���m�F
	DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	EXPECT_EQ(1, it.GetConstData().score);
	EXPECT_EQ("a", it.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�����R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-43\n
				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃R���X�g�C�e���[�^�̈�O�̃f�[�^���p�ӂ�����ڂ̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenListIsTwoData)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// �p�ӂ����f�[�^�ƈ�v���邩���m�F
	DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	EXPECT_EQ(1, it.GetConstData().score);
	EXPECT_EQ("a", it.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�����R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-44\n
				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃R���X�g�C�e���[�^�̈�O�̃f�[�^���擪�̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenDataInsert)
{
	// �f�[�^���O�p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// �f�[�^��}��
	// �擪�Ɩ����ƒ����̃C�e���[�^�ł��ꂼ��m�F����

	// �擪�ɑ}�����s�����ꍇ�̊m�F
	DoublyLinkedList::ConstIterator it4 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	EXPECT_EQ(1, it.GetConstData().score);
	EXPECT_EQ("a", it.GetConstData().userName);

	// �����ɑ}�����s�����ꍇ�̊m�F
	//DoublyLinkedList::ConstIterator it4 = ++list.GetTopConstIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//EXPECT_EQ(1, it.GetConstData().score);
	//EXPECT_EQ("a", it.GetConstData().userName);

	// �����ɑ}�����s�����ꍇ�̊m�F
	//DoublyLinkedList::ConstIterator it4 = list.GetEndConstIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//EXPECT_EQ(4, it.GetConstData().score);
	//EXPECT_EQ("dddd", it.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�����R���X�g�C�e���[�^�̎擾�@�\�ɂ��āA�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����̃e�X�g
	@details	ID:���X�g-45\n
				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋������m�F���Ă��܂��B\n
				�߂�l�̃R���X�g�C�e���[�^�̃f�[�^���擪�̃f�[�^�ƈ�v����ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenDataRemove)
{
	// �f�[�^���O�p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// �f�[�^���폜
	// �擪�Ɩ����ƒ����̃C�e���[�^�ł��ꂼ��m�F����

	// �擪�̍폜���s�����ꍇ�̊m�F
	DoublyLinkedList::ConstIterator removeIt = list.GetTopConstIterator();
	ASSERT_TRUE(list.Remove(removeIt));
	DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	EXPECT_EQ(1, it.GetConstData().score);
	EXPECT_EQ("a", it.GetConstData().userName);

	// �����̍폜���s�����ꍇ�̊m�F
	//DoublyLinkedList::ConstIterator removeIt = ++list.GetTopConstIterator();
	//ASSERT_TRUE(list.Remove(removeIt));
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//EXPECT_EQ(1, it.GetConstData().score);
	//EXPECT_EQ("a", it.GetConstData().userName);

	// �����̍폜���s�����ꍇ�̊m�F
	//DoublyLinkedList::ConstIterator removeIt = --list.GetEndConstIterator();
	//ASSERT_TRUE(list.Remove(removeIt));
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//EXPECT_EQ(2, it.GetConstData().score);
	//EXPECT_EQ("bb", it.GetConstData().userName);
}