//============================================================
//
//  title  : �C�e���[�^�[�̎����e�X�g�R�[�h [outoIteratorTest.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/11
//  Update : 2021/10/22
//
//============================================================
#include "gtest/gtest.h"
#include "gtest/gtest-death-test.h"
#include "../DoublyLinkedList/doublyLinkedList.h"


//--------------------------------------------------------------------------------
// �R���p�C���֘A�����e�X�g
//--------------------------------------------------------------------------------

//======================== �C�e���[�^�̎w���v�f���擾���� =============================
/**********************************************************************************//**
	@brief		�C�e���[�^�̎w���v�f���擾����@�\�ɂ��āA���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-0\n
				�C�e���[�^�̎w���v�f���擾����@�\�̃e�X�g�ł��B\n
				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetIteratorData, NotListDeathTest)
{
	DoublyLinkedList::Iterator it1;
	DoublyLinkedList::ConstIterator it2;

	// ���X�g�ւ̎Q�Ƃ��Ȃ��̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
	EXPECT_DEATH(it1.GetData(), "Assertion failed.*");
	EXPECT_DEATH(it2.GetConstData(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		�C�e���[�^�̎w���v�f���擾����@�\�ɂ��āAIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N�̃e�X�g
	@details	ID:Iterator-1\n
				�C�e���[�^�̎w���v�f���擾����@�\�̃e�X�g�ł��B\n
				Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N���m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetIteratorData, GetIteratorSubstitutionTest)
{
	// �f�[�^��p��
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// �f�[�^�̑��
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	it.GetData().score = 2;

	// �ύX�����l�ƈ�v���邩���m�F
	EXPECT_EQ(2, list.GetTopIterator().GetData().score);
}

/**********************************************************************************//**
	@brief		�C�e���[�^�̎w���v�f���擾����@�\�ɂ��āA���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-3\n
				�C�e���[�^�̎w���v�f���擾����@�\�̃e�X�g�ł��B\n
				���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetIteratorData, GetTopIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(list.GetTopIterator().GetData(), "Assertion failed.*");
	EXPECT_DEATH(list.GetTopConstIterator().GetConstData(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		�C�e���[�^�̎w���v�f���擾����@�\�ɂ��āA�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-4\n
				�C�e���[�^�̎w���v�f���擾����@�\�̃e�X�g�ł��B\n
				�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestGetIteratorData, GetEndIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(list.GetEndIterator().GetData(), "Assertion failed.*");
	EXPECT_DEATH(list.GetEndConstIterator().GetConstData(), "Assertion failed.*");
}



//================= �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂� ======================

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�ɂ��āA���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-5\n
				�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, NotListDeathTest)
{
	DoublyLinkedList::Iterator it1;
	DoublyLinkedList::ConstIterator it2;

	// ���X�g�ւ̎Q�Ƃ��Ȃ��̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
	EXPECT_DEATH(++it1, "Assertion failed.*");
	EXPECT_DEATH(++it2, "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�ɂ��āA���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-6\n
				�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetTopIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(++list.GetTopIterator(), "Assertion failed.*");
	EXPECT_DEATH(++list.GetTopConstIterator(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�ɂ��āA�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-7\n
				�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetEndIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(++list.GetEndIterator(), "Assertion failed.*");
	EXPECT_DEATH(++list.GetEndConstIterator(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�ɂ��āA���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-8\n
				�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
				���̗v�f���w���Ă���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetEndIteratorWhenListIsTwoDataTest)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// �C�e���[�^�̊m�F
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);
	++it;
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// �R���X�g�C�e���[�^�̊m�F
	DoublyLinkedList::ConstIterator constIt = list.GetTopConstIterator();
	EXPECT_EQ(2, constIt.GetConstData().score);
	EXPECT_EQ("bb", constIt.GetConstData().userName);
	++constIt;
	EXPECT_EQ(1, constIt.GetConstData().score);
	EXPECT_EQ("a", constIt.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�ɂ��āA
	            �O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )�̃e�X�g
	@details	ID:Iterator-9\n
				�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				�O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )���m�F���Ă��܂��B\n
				���̗v�f���w���Ă���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetEndIteratorPreIncrementTest)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	DoublyLinkedList::Iterator it = list.GetTopIterator();

	// �C���N�������g������O�̊m�F
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);

	// �C���N�������g������
	++it;

	// �C���N�������g��������̊m�F
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�ɂ��āA
				��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )�̃e�X�g
	@details	ID:Iterator-10\n
				�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )���m�F���Ă��܂��B\n
				���̗v�f���w���Ă���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetEndIteratorRetIncrementTest)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	DoublyLinkedList::Iterator it = list.GetTopIterator();

	// �C���N�������g������O�̊m�F
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);

	// �C���N�������g������
	it++;

	// �C���N�������g��������̊m�F
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
}



//================= �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂� ======================

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�ɂ��āA���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-11\n
				�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListTop, NotListDeathTest)
{
	DoublyLinkedList::Iterator it1;
	DoublyLinkedList::ConstIterator it2;

	// ���X�g�ւ̎Q�Ƃ��Ȃ��̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
	EXPECT_DEATH(--it1, "Assertion failed.*");
	EXPECT_DEATH(--it2, "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�ɂ��āA���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-12\n
				�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetEndIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(--list.GetEndIterator(), "Assertion failed.*");
	EXPECT_DEATH(--list.GetEndConstIterator(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�ɂ��āA�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-13\n
				�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋������m�F���Ă��܂��B\n
				Assert����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetTopIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(--list.GetTopIterator(), "Assertion failed.*");
	EXPECT_DEATH(--list.GetTopConstIterator(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�ɂ��āA���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋����̃e�X�g
	@details	ID:Iterator-14\n
				�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
				���̗v�f���w���Ă���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetTopIteratorWhenListIsTwoDataTest)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// �C�e���[�^�̊m�F
	DoublyLinkedList::Iterator it = list.GetEndIterator();
	--it;
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
	--it;
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);

	// �R���X�g�C�e���[�^�̊m�F
	DoublyLinkedList::ConstIterator constIt = list.GetEndConstIterator();
	++constIt;
	EXPECT_EQ(1, constIt.GetConstData().score);
	EXPECT_EQ("a", constIt.GetConstData().userName);
	++constIt;
	EXPECT_EQ(2, constIt.GetConstData().score);
	EXPECT_EQ("bb", constIt.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�ɂ��āA
				�O�u�f�N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )�̃e�X�g
	@details	ID:Iterator-15\n
				�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				�O�u�f�N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )���m�F���Ă��܂��B\n
				���̗v�f���w���Ă���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetTopIteratorPreIncrementTest)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// �C�e���[�^�̊m�F
	DoublyLinkedList::Iterator it = list.GetEndIterator();
	--it;

	// �f�N�������g������O�̊m�F
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// �f�N�������g������
	--it;

	// �f�N�������g��������̊m�F
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�ɂ��āA
				��u�f�N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )�̃e�X�g
	@details	ID:Iterator-16\n
				�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�@�\�̃e�X�g�ł��B\n
				��u�f�N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )���m�F���Ă��܂��B\n
				���̗v�f���w���Ă���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetTopIteratorRetIncrementTest)
{
	// �f�[�^���p�ӂ���
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	DoublyLinkedList::Iterator it = list.GetEndIterator();
	it--;

	// �f�N�������g������O�̊m�F
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// �f�N�������g������
	it--;

	// �f�N�������g��������̊m�F
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);
}


//=========================== �C�e���[�^�̃R�s�[���s�� ================================

/**********************************************************************************//**
	@brief		�C�e���[�^�̃R�s�[���s���@�\�ɂ��āA
				�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N�̃e�X�g
	@details	ID:Iterator-18\n
				�C�e���[�^�̃R�s�[���s���@�\�̃e�X�g�ł��B\n
				�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N���m�F���Ă��܂��B\n
				�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ�������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorCopy, GetIteratorCopyIqualTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	
	// �C�e���[�^�̊m�F
	it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2(it1);
	EXPECT_EQ(1, it2.GetData().score);
	EXPECT_EQ("a", it2.GetData().userName);

	// �R���X�g�C�e���[�^�̊m�F
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2(constIt1);
	EXPECT_EQ(1, constIt2.GetConstData().score);
	EXPECT_EQ("a", constIt2.GetConstData().userName);
}


//=========================== �C�e���[�^�̑�����s�� ==================================

/**********************************************************************************//**
	@brief		�C�e���[�^�̑�����s���@�\�ɂ��āA
				�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N�̃e�X�g
	@details	ID:Iterator-20\n
				�C�e���[�^�̑�����s���@�\�̃e�X�g�ł��B\n
				�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N���m�F���Ă��܂��B\n
				�����̒l���R�s�[���Ɠ�������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestIteratorSubstitution, GetIteratorSubstitutionIqualTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// �C�e���[�^�̊m�F
	it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = it1;
	EXPECT_EQ(1, it2.GetData().score);
	EXPECT_EQ("a", it2.GetData().userName);

	// �R���X�g�C�e���[�^�̊m�F
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = constIt1;
	EXPECT_EQ(1, constIt2.GetConstData().score);
	EXPECT_EQ("a", constIt2.GetConstData().userName);
}


//============== ��̃C�e���[�^������̂��̂ł��邩�A��r���s��======================

/**********************************************************************************//**
	@brief		��̃C�e���[�^������̂��̂ł��邩�A��r���s���@�\�ɂ��āA
				���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N�̃e�X�g
	@details	ID:Iterator-21\n
				��̃C�e���[�^������̂��̂ł��邩�A��r���s���@�\�̃e�X�g�ł��B\n
				��̃C�e���[�^������̂��̂ł��邩�A��r���s�����`�F�b�N���m�F���Ă��܂��B\n
				�����̒l���R�s�[���Ɠ�������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestTwoIteratorIqual, TwoIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	
	EXPECT_EQ(true, list.GetTopIterator().GetData().score == list.GetEndIterator().GetData().score);
	EXPECT_EQ(true, list.GetTopIterator().GetData().userName == list.GetEndIterator().GetData().userName);
	EXPECT_EQ(true, list.GetTopConstIterator().GetConstData().score == list.GetEndConstIterator().GetConstData().score);
	EXPECT_EQ(true, list.GetTopConstIterator().GetConstData().userName == list.GetEndConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		��̃C�e���[�^������̂��̂ł��邩�A��r���s���@�\�ɂ��āA
				����̃C�e���[�^���r�����ۂ̋����̃e�X�g
	@details	ID:Iterator-22\n
				��̃C�e���[�^������̂��̂ł��邩�A��r���s���@�\�̃e�X�g�ł��B\n
				����̃C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
				�����̒l���R�s�[���Ɠ�������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestTwoIteratorIqual, IqualIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));

	// �C�e���[�^�̊m�F
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	EXPECT_EQ(true, it1.GetData().score == it2.GetData().score);
	EXPECT_EQ(true, it1.GetData().userName == it2.GetData().userName);

	// �R���X�g�C�e���[�^�̊m�F
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = list.GetTopConstIterator();
	EXPECT_EQ(true, constIt1.GetConstData().score == constIt2.GetConstData().score);
	EXPECT_EQ(true, constIt1.GetConstData().userName == constIt2.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		��̃C�e���[�^������̂��̂ł��邩�A��r���s���@�\�ɂ��āA
				�قȂ�C�e���[�^���r�����ۂ̋����̃e�X�g
	@details	ID:Iterator-23\n
				��̃C�e���[�^������̂��̂ł��邩�A��r���s���@�\�̃e�X�g�ł��B\n
				�قȂ�C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
				�����̒l���R�s�[���Ɠ�������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestTwoIteratorIqual, NotIqualIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator ite1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(ite1, 1, "a"));
	DoublyLinkedList::Iterator ite2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(ite2, 2, "bb"));

	// �C�e���[�^�̊m�F
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = ++list.GetTopIterator();
	EXPECT_EQ(false, it1.GetData().score == it2.GetData().score);
	EXPECT_EQ(false, it1.GetData().userName == it2.GetData().userName);

	// �R���X�g�C�e���[�^�̊m�F
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = ++list.GetTopConstIterator();
	EXPECT_EQ(false, constIt1.GetConstData().score == constIt2.GetConstData().score);
	EXPECT_EQ(false, constIt1.GetConstData().userName == constIt2.GetConstData().userName);
}



//============== ��̃C�e���[�^���قȂ���̂ł��邩�A��r���s��======================

/**********************************************************************************//**
	@brief		��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���@�\�ɂ��āA
				���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N�̃e�X�g
	@details	ID:Iterator-21\n
				��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���@�\�̃e�X�g�ł��B\n
				��̃C�e���[�^������̂��̂ł��邩�A��r���s�����`�F�b�N���m�F���Ă��܂��B\n
				�����̒l���R�s�[���Ɠ�������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestTwoIteratorNotIqual, TwoIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;

	EXPECT_EQ(false, list.GetTopIterator().GetData().score != list.GetEndIterator().GetData().score);
	EXPECT_EQ(false, list.GetTopIterator().GetData().userName != list.GetEndIterator().GetData().userName);
	EXPECT_EQ(false, list.GetTopConstIterator().GetConstData().score != list.GetEndConstIterator().GetConstData().score);
	EXPECT_EQ(false, list.GetTopConstIterator().GetConstData().userName != list.GetEndConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���@�\�ɂ��āA
				����̃C�e���[�^���r�����ۂ̋����̃e�X�g
	@details	ID:Iterator-22\n
				��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���@�\�̃e�X�g�ł��B\n
				����̃C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
				�����̒l���R�s�[���Ɠ�������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestTwoIteratorNotIqual, IqualIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));

	// �C�e���[�^�̊m�F
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	EXPECT_EQ(false, it1.GetData().score != it2.GetData().score);
	EXPECT_EQ(false, it1.GetData().userName != it2.GetData().userName);

	// �R���X�g�C�e���[�^�̊m�F
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = list.GetTopConstIterator();
	EXPECT_EQ(false, constIt1.GetConstData().score != constIt2.GetConstData().score);
	EXPECT_EQ(false, constIt1.GetConstData().userName != constIt2.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���@�\�ɂ��āA
				�قȂ�C�e���[�^���r�����ۂ̋����̃e�X�g
	@details	ID:Iterator-23\n
				��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���@�\�̃e�X�g�ł��B\n
				�قȂ�C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
				�����̒l���R�s�[���Ɠ�������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestTwoIteratorNotIqual, NotIqualIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator ite1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(ite1, 1, "a"));
	DoublyLinkedList::Iterator ite2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(ite2, 2, "bb"));

	// �C�e���[�^�̊m�F
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = ++list.GetTopIterator();
	EXPECT_EQ(true, it1.GetData().score != it2.GetData().score);
	EXPECT_EQ(true, it1.GetData().userName != it2.GetData().userName);

	// �R���X�g�C�e���[�^�̊m�F
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = ++list.GetTopConstIterator();
	EXPECT_EQ(true, constIt1.GetConstData().score != constIt2.GetConstData().score);
	EXPECT_EQ(true, constIt1.GetConstData().userName != constIt2.GetConstData().userName);
}