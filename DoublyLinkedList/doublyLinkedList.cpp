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
//�@�R���X�g�C�e���[�^�N���X�̊֐�
//============================================================
//------------------------------------------------------------
//�y �R���X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator::ConstIterator()
{
	;
}


//------------------------------------------------------------
//�y �����t���R���X�g���N�^ �z
// thisPtr�F
//------------------------------------------------------------
DoublyLinkedList::ConstIterator::ConstIterator(Node* thisPtr)
{
	itePtr = thisPtr;
}


//------------------------------------------------------------
//�y �f�X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator::~ConstIterator()
{
	;
}


//------------------------------------------------------------
//�y ���X�g�̖����������Ĉ�i�߂� �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++()
{
	// �G���[�`�F�b�N
	if (itePtr->nextPtr->recordData.score == 0 && itePtr->nextPtr->recordData.userName == "")
	{
		//return;
	}

	itePtr = itePtr->nextPtr;
	return *this;
}


//------------------------------------------------------------
//�y ���X�g�̐擪�Ɍ������Ĉ�i�߂� �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--()
{
	// �G���[�`�F�b�N
	if (itePtr->prevPtr->recordData.score == 0 && itePtr->prevPtr->recordData.userName == "")
	{
		//return;
	}

	itePtr = itePtr->prevPtr;
	return *this;
}


//------------------------------------------------------------
//�y == ��r�̃I�y���[�^�[ �z
// ite�F��r����C�e���[�^�I�u�W�F�N�g
//------------------------------------------------------------
bool DoublyLinkedList::ConstIterator::operator ==(const ConstIterator &ite) const
{
	return *this == ite;
}


//------------------------------------------------------------
//�y != ��r�̃I�y���[�^�[ �z
// ite�F��r����C�e���[�^�I�u�W�F�N�g
//------------------------------------------------------------
bool DoublyLinkedList::ConstIterator::operator !=(const ConstIterator &ite) const
{
	return !(*this == ite);
}


//------------------------------------------------------------
//�y �C�e���[�^�̎w���v�f���擾���� �z
//------------------------------------------------------------
const RecordData& DoublyLinkedList::ConstIterator::GetConstData()
{
	return itePtr->recordData;
}



//============================================================
//�@�C�e���[�^�N���X�̊֐�
//============================================================
//------------------------------------------------------------
//�y �R���X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::Iterator::Iterator()
{
	;
}


//------------------------------------------------------------
//�y �����t���R���X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::Iterator::Iterator(Node* thisPtr)
{
	itePtr = thisPtr;
}


//------------------------------------------------------------
//�y �f�X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::Iterator::~Iterator()
{
	;
}


//------------------------------------------------------------
//�y �C�e���[�^�̎w���v�f���擾���� �z
//------------------------------------------------------------
RecordData& DoublyLinkedList::Iterator::GetData()
{
	return itePtr->recordData;
}



//============================================================
//�@�o�������X�g�N���X�̊֐�
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
	;
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
	Node* temp = thisPtr->nextPtr;

	while (temp != nullptr)
	{
		// �����Ɉ�i�߂�
		temp = temp->nextPtr;

		// �f�[�^�̐����J�E���g
		dataCount++;
	}

	// �f�[�^�̐���Ԃ�
	return dataCount;
}


//------------------------------------------------------------
//�@�y �f�[�^�̑}�� �z
//�@addIterator�F�ǉ�����C�e���[�^�̏��
//------------------------------------------------------------
void DoublyLinkedList::Insert(Iterator addIterator)
{
	// �ǉ�����f�[�^���쐬
	Node* temp = new Node();
	temp->recordData.score = addIterator.GetData().score;
	temp->recordData.userName = addIterator.GetData().userName;

	// �����̃|�C���^��ۑ�
	Node* endPtr = thisPtr->prevPtr;

	if (endPtr == nullptr)
	{
		// �����Ƀf�[�^���Ȃ��ꍇ��temp�𖖔��f�[�^�Ƃ���
		endPtr = temp;

		// temp�̐��thisPtr�ɂ���
		temp->nextPtr = thisPtr;

		// thisPtr�̑O��̐ڑ�����ǂ����temp�ɂ���
		thisPtr->nextPtr = temp;
		thisPtr->prevPtr = temp;
	}
	else
	{
		endPtr->nextPtr = temp;
		temp->prevPtr = endPtr;
		temp->nextPtr = thisPtr;
		thisPtr->prevPtr = temp;
	}
}


//------------------------------------------------------------
//�@�y �f�[�^�̍폜 �z
//�@removeIterator�F�폜����C�e���[�^�̏��
//------------------------------------------------------------
void DoublyLinkedList::Remove(Iterator removeIterator)
{
	// �擪�̃|�C���^��ۑ�
	Node* temp = thisPtr->nextPtr;

	if (temp == nullptr)
	{
		// �f�[�^���Ȃ��ꍇ��return
		return;
	}
	
	while (temp != nullptr)
	{

	}
}


//------------------------------------------------------------
//�@�y �擪�C�e���[�^�擾 �z
//�@return�F�擪�̃C�e���[�^
//------------------------------------------------------------
DoublyLinkedList::Iterator DoublyLinkedList::GetTopIterator()
{
	DoublyLinkedList::Iterator temp(thisPtr->nextPtr);

	// �G���[�`�F�b�N
	if (temp == NULL)
	{
		return NULL;
	}

	// �擪�C�e���[�^��Ԃ�
	return temp;
}


//------------------------------------------------------------
//�@�y �擪�R���X�g�C�e���[�^�擾 �z
//�@return�F�擪�R���X�g�C�e���[�^
//------------------------------------------------------------
DoublyLinkedList::ConstIterator DoublyLinkedList::GetTopConstIterator()
{
	DoublyLinkedList::ConstIterator temp(thisPtr->nextPtr);

	// �G���[�`�F�b�N
	if (temp == NULL)
	{
		return NULL;
	}

	// �擪�C�e���[�^��Ԃ�
	return temp;
}


//------------------------------------------------------------
//�@�y �����C�e���[�^�擾 �z
//�@return�F�����C�e���[�^
//------------------------------------------------------------
DoublyLinkedList::Iterator DoublyLinkedList::GetEndIterator()
{
	DoublyLinkedList::Iterator temp(thisPtr->prevPtr);

	// �G���[�`�F�b�N
	if (temp == NULL)
	{
		return NULL;
	}

	// �擪�C�e���[�^��Ԃ�
	return temp;
}


//------------------------------------------------------------
//�@�y �����R���X�g�C�e���[�^�擾 �z
//�@return�F�����R���X�g�C�e���[�^
//------------------------------------------------------------
DoublyLinkedList::ConstIterator DoublyLinkedList::GetEndConstIterator()
{
	DoublyLinkedList::ConstIterator temp(thisPtr->prevPtr);

	// �G���[�`�F�b�N
	if (temp == NULL)
	{
		return NULL;
	}

	// �擪�C�e���[�^��Ԃ�
	return temp;
}
