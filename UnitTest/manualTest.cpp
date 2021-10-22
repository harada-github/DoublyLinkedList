//============================================================
//
//  title  : GoogleTest�蓮�e�X�g�R�[�h [test.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/11
//  Update : 2021/10/22
//
//============================================================
#include "pch.h"


//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------

//=================================== �f�[�^���̎擾 ===================================
/**********************************************************************************//**
	@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
	@details	ID:���X�g-8(�蓮)\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_DATA_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataCountIsConstTest)
{
#if defined TT_TEST_DATA_COUNT_IS_CONST
	const DoublyLinkedList list;
	EXPECT_EQ(0, list.GetDataCount());

#endif //TT_TEST_DATA_IS_CONST
	SUCCEED();
}


//=================================== �f�[�^�̑}�� ===================================
/**********************************************************************************//**
	@brief		�f�[�^�̑}���@�\�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
	@details	ID:���X�g-15(�蓮)\n
				�f�[�^�̑}���@�\�̃e�X�g�ł��B\n
				��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł��B\n
				TT_TEST_DATA_INSERT_IS_NO_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestInsertData, DataInsertIsNoConstTest)
{
#if defined TT_TEST_DATA_INSERT_IS_NO_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	EXPECT_EQ(0, list.Insert(it, 1, "a"));

#endif //TT_TEST_DATA_INSERT_IS_NO_CONST
	SUCCEED();
}


//=================================== �f�[�^�̍폜 ===================================
/**********************************************************************************//**
	@brief		�f�[�^�̍폜�@�\�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
	@details	ID:���X�g-22\n
				�f�[�^�̍폜�@�\�̃e�X�g�ł��B\n
				��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł��B\n
				TT_TEST_DATA_REMOVE_IS_NO_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestRemoveData, DataRemoveIsNoConstTest)
{
#if defined TT_TEST_DATA_REMOVE_IS_NO_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	EXPECT_EQ(0, list.Remove(it));

#endif //TT_TEST_DATA_REMOVE_IS_NO_CONST
	SUCCEED();
}


//=============================== �擪�C�e���[�^�̎擾 ================================
/**********************************************************************************//**
	@brief		�擪�C�e���[�^�̎擾�@�\�ɂ��āAconst�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N�̃e�X�g
	@details	ID:���X�g-28\n
				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł��B\n
				TT_TEST_CONSTLIST_GET_TOPITERATOR�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestGetTopIterator, ConstListGetTopIteratorTest)
{
#if defined TT_TEST_CONSTLIST_GET_TOPITERATOR
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();

#endif //TT_TEST_CONSTLIST_GET_TOPITERATOR
	SUCCEED();
}


//======================== �擪�R���X�g�C�e���[�^�̎擾 ================================
/**********************************************************************************//**
	@brief		�擪�R���X�g�C�e���[�^�̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
	@details	ID:���X�g-34\n
				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_CONSTLIST_GET_TOPCONSTITERATOR�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, ConstListGetTopConstIteratorTest)
{
#if defined TT_TEST_CONSTLIST_GET_TOPCONSTITERATOR
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();

#endif //TT_TEST_CONSTLIST_GET_TOPCONSTITERATOR
	SUCCEED();
}


//=============================== �����C�e���[�^�̎擾 ================================
/**********************************************************************************//**
	@brief		�����C�e���[�^�̎擾�@�\�ɂ��āAconst�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N�̃e�X�g
	@details	ID:���X�g-40\n
				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł��B\n
				TT_TEST_CONSTLIST_GET_ENDITERATOR�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestGetTopIterator, ConstListGetEndIteratorTest)
{
#if defined TT_TEST_CONSTLIST_GET_ENDITERATOR
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetEndIterator();

#endif //TT_TEST_CONSTLIST_GET_ENDITERATOR
	SUCCEED();
}


//======================== �����R���X�g�C�e���[�^�̎擾 ================================
/**********************************************************************************//**
	@brief		�����R���X�g�C�e���[�^�̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
	@details	ID:���X�g-46\n
				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
				const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_CONSTLIST_GET_ENDCONSTITERATOR�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, ConstListGetEndConstIteratorTest)
{
#if defined TT_TEST_CONSTLIST_GET_ENDCONSTITERATOR
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetEndConstIterator();

#endif //TT_TEST_CONSTLIST_GET_ENDCONSTITERATOR
	SUCCEED();
}


//======================== �C�e���[�^�̎w���v�f���擾���� =============================
/**********************************************************************************//**
	@brief		�C�e���[�^�̎w���v�f���擾����@�\�ɂ��āAConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N�̃e�X�g
	@details	ID:Iterator-2\n
				�C�e���[�^�̎w���v�f���擾����@�\�̃e�X�g�ł��B\n
				ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł��B\n
				TT_TEST_GET_CONSTITERATOR_SUBSTITUTION�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestGetIteratorData, GetConstIteratorSubstitutionTest)
{
#if defined TT_TEST_GET_CONSTITERATOR_SUBSTITUTION

	// �f�[�^��p��
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// �f�[�^�̑��
	RecordData data = {2, "bb"};
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	it.GetConstData() = data;


#endif //TT_TEST_GET_CONSTITERATOR_SUBSTITUTION
	SUCCEED();
}


//=========================== �C�e���[�^�̃R�s�[���s�� ================================

/**********************************************************************************//**
	@brief		�C�e���[�^�̃R�s�[���s���@�\�ɂ��āA
				ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N�̃e�X�g
	@details	ID:Iterator-17\n
				�C�e���[�^�̃R�s�[���s���@�\�̃e�X�g�ł��B\n
				ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł��B\n
				TT_TEST_ITERATOR_COPY�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestIteratorCopy, GetTopIteratorCopyIqualTest)
{
#if defined TT_TEST_ITERATOR_COPY

	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1;
	DoublyLinkedList::Iterator it2(it1);

#endif //TT_TEST_ITERATOR_COPY
	SUCCEED();
}


//=========================== �C�e���[�^�̑�����s�� ==================================
/**********************************************************************************//**
	@brief		�C�e���[�^�̑�����s���@�\�ɂ��āA
				Iterator��ConstIterator�����ł��Ȃ������`�F�b�N�̃e�X�g
	@details	ID:Iterator-19\n
				�C�e���[�^�̑�����s���@�\�̃e�X�g�ł��B\n
				Iterator��ConstIterator�����ł��Ȃ������`�F�b�N���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł��B\n
				TT_TEST_ITERATOR_SUBSTITUTION�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(TestIteratorSubstitution, IteratorSubstitutionConstIteratorTest)
{
#if defined TT_TEST_ITERATOR_SUBSTITUTION

	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1;
	DoublyLinkedList::ConstIterator it2;
	it1 = it2;

#endif //TT_TEST_ITERATOR_SUBSTITUTION
	SUCCEED();
}