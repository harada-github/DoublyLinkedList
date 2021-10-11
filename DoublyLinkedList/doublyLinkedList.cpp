//============================================================
//
//  title  : �o�������X�g�N���X [doublyLinkedList.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/07
//  Update : 2021/10/07
//
//============================================================
#include "doublyLinkedList.h"


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@�y �R���X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::DoublyLinkedList()
{
	// �l��������
	thisPtr = nullptr;
}


//------------------------------------------------------------
//�@�y �f�X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::~DoublyLinkedList()
{
	// �������
	Node* temp = GetTopPtr();
	Node* dele = nullptr;

	// temp �� NULL ����Ȃ���delete
	while (temp != nullptr)
	{
		dele = temp;

		temp = temp->nextPtr;

		delete dele;
	}
}


//------------------------------------------------------------
//�@�y �擪�Ƀf�[�^��ǉ� �z
//�@addRecordData�F�ǉ����������уf�[�^
//------------------------------------------------------------
void DoublyLinkedList::AddTop(RecordData addRecordData)
{
	// �擪�̃m�[�h�ւ̃|�C���^���i�[
	Node* topPtr = GetTopPtr();

	// topPtr �� NULL �̏ꍇ�͍ŏ��̃f�[�^�Ƃ��� topPtr �ɒǉ�
	if (topPtr == nullptr)
	{
		topPtr = new Node();

		// ��������f�[�^��ǉ�
		topPtr->recordData.score = addRecordData.score;
		topPtr->recordData.userName = addRecordData.userName;

		// �O��̃|�C���^���X�V
		topPtr->prevPtr = nullptr;
		topPtr->nextPtr = nullptr;

		// thisPtr ���X�V
		thisPtr = topPtr;
	}
	// topPtr��NULL����Ȃ���Ύ��̃m�[�h�ւ̃|�C���^�Ƀf�[�^��ǉ�
	else
	{
		topPtr->prevPtr = new Node();

		// ��������f�[�^��ǉ�
		topPtr->prevPtr->recordData.score = addRecordData.score;
		topPtr->prevPtr->recordData.userName = addRecordData.userName;

		// �O��̃|�C���^���X�V
		topPtr->prevPtr->nextPtr = topPtr;
		topPtr->prevPtr->prevPtr = nullptr;

		// thisPtr ���X�V
		thisPtr = topPtr->prevPtr;
	}
}


//------------------------------------------------------------
//�@�y �����Ƀf�[�^��ǉ� �z
//�@addRecordData�F�ǉ����������уf�[�^
//------------------------------------------------------------
void DoublyLinkedList::AddEnd(RecordData addRecordData)
{
	// �����̃m�[�h�ւ̃|�C���^���i�[
	Node* endPtr = GetEndPtr();

	// endPtr �� NULL �̏ꍇ�͍ŏ��̃f�[�^�Ƃ��� endPtr �ɒǉ�
	if (endPtr == nullptr)
	{
		endPtr = new Node();

		// ��������f�[�^��ǉ�
		endPtr->recordData.score = addRecordData.score;
		endPtr->recordData.userName = addRecordData.userName;

		// �O��̃|�C���^���X�V
		endPtr->prevPtr = nullptr;
		endPtr->nextPtr = nullptr;

		// thisPtr ���X�V
		thisPtr = endPtr;
	}
	// endPtr��NULL����Ȃ���Ύ��̃m�[�h�ւ̃|�C���^�Ƀf�[�^��ǉ�
	else
	{
		endPtr->nextPtr = new Node();

		// ��������f�[�^��ǉ�
		endPtr->nextPtr->recordData.score = addRecordData.score;
		endPtr->nextPtr->recordData.userName = addRecordData.userName;

		// �O��̃|�C���^���X�V
		endPtr->nextPtr->prevPtr = endPtr;
		endPtr->nextPtr->nextPtr = nullptr;

		// thisPtr ���X�V
		thisPtr = endPtr->nextPtr;
	}
}


//------------------------------------------------------------
//�@�y �擪�̃m�[�h���擾 �z
//�@return�F�擪�̃m�[�h�̃|�C���^
//�@���m�[�h�i�v�f�j���O�̏ꍇ�� NULL �̏�ԂŕԂ�
//------------------------------------------------------------
DoublyLinkedList::Node* DoublyLinkedList::GetTopPtr()
{
	// �擪�̃m�[�h�ւ̃|�C���^���i�[
	Node* topPtr = thisPtr;

	// topPtr �� NULL �̏ꍇ�͂��̂܂ܕԂ�
	if (topPtr != nullptr)
	{
		// ���̃m�[�h�ւ̃|�C���^��NULL�ɂȂ�܂Ŋm�F
		while (topPtr->prevPtr != nullptr)
		{
			topPtr = topPtr->prevPtr;
		}
	}

	// �擪�̃m�[�h�ւ̃|�C���^��Ԃ�
	return topPtr;
}


//------------------------------------------------------------
//�@�y �����̃m�[�h���擾 �z
//�@return�F�����̃m�[�h�̃|�C���^
//�@���m�[�h�i�v�f�j���O�̏ꍇ�� NULL �̏�ԂŕԂ�
//------------------------------------------------------------
DoublyLinkedList::Node* DoublyLinkedList::GetEndPtr()
{
	// �����̃m�[�h�ւ̃|�C���^���i�[
	Node* endPtr = thisPtr;

	// endPtr �� NULL �̏ꍇ�͂��̂܂ܕԂ�
	if (endPtr != nullptr)
	{
		// ���̃m�[�h�ւ̃|�C���^��NULL�ɂȂ�܂Ŋm�F
		while (endPtr->nextPtr != nullptr)
		{
			endPtr = endPtr->nextPtr;
		}
	}

	// �����̃m�[�h�ւ̃|�C���^��Ԃ�
	return endPtr;
}


//------------------------------------------------------------
//�@�y �\�[�g�i���ёւ��j �z
//------------------------------------------------------------
void DoublyLinkedList::Sort()
{
	// �f�[�^�̐����擾
	int dataCount = GetDataCount();

	// �P�ȉ��Ȃ�return
	if (dataCount <= 1) return;

	// �擪�Ɩ����̃|�C���^���擾
	Node* topPtr = GetTopPtr();
	Node* endPtr = GetEndPtr();

	// ����ւ��Ɏg�p���邽�߂̕ϐ�
	Node *data1, *data2;

	for (int j = 0; j < dataCount - 1; j++)
	{
		// �擪�Ƃ��̎��̃A�h���X���r
		data1 = topPtr;
		data2 = data1->nextPtr;

		for (int i = 0; i < dataCount - 1 - j; i++)
		{
			// list2��score�������ꍇ�͓���ւ�
			if (data1->recordData.score < data2->recordData.score)
			{
				// list1�̎���list2�̑O�̐ڑ����ύX
				data1->nextPtr = data2->nextPtr;
				data2->prevPtr = data1->prevPtr;

				// ����ւ���̂��ꂼ����Ȃ�
				data2->nextPtr = data1;
				data1->prevPtr = data2;

				// ����ւ���O��list1��list2�̑O��̐ڑ����ύX
				if (data1 == topPtr)
				{
					// list1���擪�������ꍇ
					topPtr = data2;
				}
				else
				{
					data2->prevPtr->nextPtr = data2;
				}

				if (data2 == endPtr)
				{
					// list2���Ōゾ�����ꍇ
					endPtr = data1;
				}
				else
				{
					data1->nextPtr->prevPtr = data1;
				}

				// ���ɔ�r������̂�list2�֑��
				data2 = data1->nextPtr;
			}
			else
			{
				// ���ɔ�r������̂�ݒ�
				data1 = data1->nextPtr;
				data2 = data2->nextPtr;
			}
		}
	}
}


//------------------------------------------------------------
//�@�y �f�[�^�̍폜 �z
//�@num�F�폜����f�[�^�̈ʒu�i1��擪�Ƃ���j
//------------------------------------------------------------
void DoublyLinkedList::Remove(int num)
{
	// ���X�g�̗v�f�̌����擾
	int count = GetDataCount();

	// ����0 �܂��� �폜�������ʒu��0 �܂��� �폜�������ʒu�������傫����� return
	if (count == 0 || num == 0 || num > count) return;

	// �폜�Ɏg�p����ϐ�
	Node* temp;

	// �擪�Ɩ����̃|�C���^���擾
	Node* topPtr = GetTopPtr();
	Node* endPtr = GetEndPtr();

	if (count == 1)
	{
		// �v�f����̏ꍇ

		// �폜
		delete topPtr;

		// �擪�Ɩ�����NULL�ɂ���
		topPtr = endPtr = nullptr;
	}
	else if (num == 1)
	{
		// �擪�̗v�f�̏ꍇ

		// �폜����O�Ɏ��̃|�C���^��ۑ�
		temp = topPtr->nextPtr;

		// �폜
		delete topPtr;

		// �擪�̗v�f���X�V
		topPtr = temp;

		// �擪�̗v�f�ɂȂ�|�C���^�̑O�|�C���^��NULL�ɂ���
		temp->prevPtr = nullptr;
	}
	else if (num == count)
	{
		// �����̗v�f�̏ꍇ

		// �폜����O�ɑO�̃|�C���^��ۑ�
		temp = endPtr->prevPtr;

		// �폜
		delete endPtr;

		// �����̗v�f���X�V
		endPtr = temp;

		// �����̗v�f�ɂȂ�|�C���^�̎��|�C���^��NULL�ɂ���
		temp->nextPtr = nullptr;
	}
	else
	{
		// �擪�Ɩ����ȊO�̏ꍇ

		// �擪�̃|�C���^��ۑ�
		temp = topPtr;

		// num�̈ʒu�܂ł��ǂ�
		for (int i = 1; i < num; i++)
		{
			temp = temp->nextPtr;
		}

		// �폜�������ʒu�̃|�C���^�̑O����X�V
		temp->prevPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = temp->prevPtr;

		// �폜
		delete temp;
	}
}


//------------------------------------------------------------
//�@�y �f�[�^�̐��̎擾 �z
//�@return�F�f�[�^�̐�
//------------------------------------------------------------
int DoublyLinkedList::GetDataCount()
{
	// �f�[�^�̐����J�E���g����ϐ�
	int dataCount = 0;

	// �擪�|�C���^��ۑ�
	Node* temp = GetTopPtr();

	while (temp != nullptr)
	{
		// �f�[�^���J�E���g
		dataCount++;

		// ���̃|�C���^�֍X�V
		temp = temp->nextPtr;
	}

	// �f�[�^�̐���Ԃ�
	return dataCount;
}
