//============================================================
//
//  title  : �o�������X�g�N���X [doublyLinkedList.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/07
//  Update : 2021/10/22
//
//============================================================
#include "doublyLinkedList.h"
#include <assert.h>


//============================================================
//�@�R���X�g�C�e���[�^�N���X�̊֐�
//============================================================
//------------------------------------------------------------
//�y �R���X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator::ConstIterator()
{
	itePtr = nullptr;
}


//------------------------------------------------------------
//�y �����t���R���X�g���N�^ �z
// thisPtr�F�o�������X�g��thisPtr�������
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
//�y ���X�g�̖����������Ĉ�i�߂�i�O�u�C���N�������g�j �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++()
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	assert(itePtr->nextPtr->recordData.score != 0);
	assert(itePtr->nextPtr->recordData.userName != "");

	itePtr = itePtr->nextPtr;
	return *this;
}


//------------------------------------------------------------
//�y ���X�g�̖����Ɍ������Ĉ�i�߂�i��u�C���N�������g�j �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++(int)
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	assert(itePtr->nextPtr->recordData.score != 0);
	assert(itePtr->nextPtr->recordData.userName != "");

	ConstIterator it = *this;

	++(*this);

	return it;
}


//------------------------------------------------------------
//�y ���X�g�̐擪�Ɍ������Ĉ�i�߂�i�O�u�f�N�������g�j �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--()
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	//assert(itePtr->recordData.score != 0);
	//assert(itePtr->recordData.userName != "");
	assert(itePtr->prevPtr->recordData.score != 0);
	assert(itePtr->prevPtr->recordData.userName != "");

	itePtr = itePtr->prevPtr;
	return *this;
}


//------------------------------------------------------------
//�y ���X�g�̐擪�Ɍ������Ĉ�i�߂�i��u�f�N�������g�j �z
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--(int)
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	//assert(itePtr->recordData.score != 0);
	//assert(itePtr->recordData.userName != "");
	assert(itePtr->prevPtr->recordData.score != 0);
	assert(itePtr->prevPtr->recordData.userName != "");

	ConstIterator it = *this;

	--(*this);

	return it;
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
//�y �R���X�g�C�e���[�^�̎w���v�f���擾���� �z
//------------------------------------------------------------
RecordData& DoublyLinkedList::ConstIterator::GetConstData() const
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	//assert(itePtr->recordData.score != 0);
	//assert(itePtr->recordData.userName != "");

	return itePtr->recordData;
}


//------------------------------------------------------------
//�y �R���X�g�C�e���[�^�̎���Node���擾���� �z
//------------------------------------------------------------
DoublyLinkedList::Node* DoublyLinkedList::ConstIterator::GetConstIteratorNode()
{
	if (itePtr == nullptr) return nullptr;

	return itePtr;
}




//============================================================
//�@�C�e���[�^�N���X�̊֐�
//============================================================
//------------------------------------------------------------
//�y �R���X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::Iterator::Iterator()
{
	itePtr = nullptr;
}


//------------------------------------------------------------
//�y �����t���R���X�g���N�^ �z
// thisPtr�F�o�������X�g��thisPtr�������
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
//�y ���X�g�̖����������Ĉ�i�߂�i�O�u�C���N�������g�j �z
//------------------------------------------------------------
DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator++()
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	assert(itePtr->nextPtr->recordData.score != 0);
	assert(itePtr->nextPtr->recordData.userName != "");

	itePtr = itePtr->nextPtr;
	return *this;
}


//------------------------------------------------------------
//�y ���X�g�̖����Ɍ������Ĉ�i�߂�i��u�C���N�������g�j �z
//------------------------------------------------------------
DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator++(int)
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	assert(itePtr->nextPtr->recordData.score != 0);
	assert(itePtr->nextPtr->recordData.userName != "");

	Iterator it = *this;

	++(*this);

	return it;
}


//------------------------------------------------------------
//�y ���X�g�̐擪�Ɍ������Ĉ�i�߂�i�O�u�f�N�������g�j �z
//------------------------------------------------------------
DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator--()
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	//assert(itePtr->recordData.score != 0);
	//assert(itePtr->recordData.userName != "");
	assert(itePtr->prevPtr->recordData.score != 0);
	assert(itePtr->prevPtr->recordData.userName != "");

	itePtr = itePtr->prevPtr;
	return *this;
}


//------------------------------------------------------------
//�y ���X�g�̐擪�Ɍ������Ĉ�i�߂�i��u�f�N�������g�j �z
//------------------------------------------------------------
DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator--(int)
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	//assert(itePtr->recordData.score != 0);
	//assert(itePtr->recordData.userName != "");
	assert(itePtr->prevPtr->recordData.score != 0);
	assert(itePtr->prevPtr->recordData.userName != "");

	Iterator it = *this;

	--(*this);

	return it;
}


//------------------------------------------------------------
//�y �C�e���[�^�̎w���v�f���擾���� �z
//------------------------------------------------------------
RecordData& DoublyLinkedList::Iterator::GetData()
{
	// �G���[�`�F�b�N
	assert(itePtr != nullptr);
	//assert(itePtr->recordData.score != 0);
	//assert(itePtr->recordData.userName != "");

	return itePtr->recordData;
}


//------------------------------------------------------------
//�y �C�e���[�^�̎���Node���擾���� �z
//------------------------------------------------------------
DoublyLinkedList::Node* DoublyLinkedList::Iterator::GetIteratorNode()
{
	if (itePtr == nullptr) return nullptr;

	return itePtr;
}



//============================================================
//�@�o�������X�g�N���X�̊֐�
//============================================================
//------------------------------------------------------------
//�@�y �R���X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::DoublyLinkedList()
{
	// �_�~�[�̃m�[�h���쐬
	thisPtr = new Node();
	//thisPtr->recordData.score = 0;
	//thisPtr->recordData.userName = "";

	// �l��������
	thisPtr->prevPtr = nullptr;
	thisPtr->nextPtr = nullptr;
}


//------------------------------------------------------------
//�@�y �f�X�g���N�^ �z
//------------------------------------------------------------
DoublyLinkedList::~DoublyLinkedList()
{
	if (thisPtr != nullptr)
	{
		delete thisPtr;
	}
}


//------------------------------------------------------------
//�@�y �f�[�^�̐��̎擾 �z
//�@return�F�f�[�^�̐�
//------------------------------------------------------------
int DoublyLinkedList::GetDataCount() const
{
	// �f�[�^�̐����J�E���g����ϐ�
	int dataCount = 0;

	// �擪�|�C���^���Ȃ����0��Ԃ�
	if (thisPtr->nextPtr == nullptr)
	{
		return dataCount;
	}
	else
	{
		// �擪�|�C���^��ۑ�
		Node* temp = thisPtr->nextPtr;

		// �擪���̃f�[�^����m��
		dataCount++;

		// ���ɂ���f�[�^��thisPtr�̃f�[�^�ƈ�v����܂�
		while (!(temp->nextPtr->recordData.score == 0 && temp->nextPtr->recordData.userName == ""))
		{
			// �����Ɉ�i�߂�
			temp = temp->nextPtr;

			// �f�[�^�̐����J�E���g
			dataCount++;
		}
	}

	// �f�[�^�̐���Ԃ�
	return dataCount;
}


//------------------------------------------------------------
//�@�y �f�[�^�̑}�� �z
//�@addIterator�F�ǉ�����C�e���[�^�̏��
//�@addScore�F�ǉ�����f�[�^�̃X�R�A���
//------------------------------------------------------------
bool DoublyLinkedList::Insert(ConstIterator addConstIterator, int addScore, char* addUserName)
{
	// �f�[�^����ێ�
	int dataCount = GetDataCount();

	// �}���p�̕ϐ�
	Node* temp = addConstIterator.GetConstIteratorNode();

	// �ǉ�����f�[�^���쐬
	Node* add = new Node();
	add->recordData.score = addScore;
	add->recordData.userName = addUserName;

	if (dataCount == 0)
	{
		// �f�[�^���Ȃ��ꍇ�͐擪�Ɩ����ɍ쐬�����f�[�^��ݒ�

		// thisPtr�̑O����쐬�����f�[�^�ɐݒ肷��
		thisPtr->nextPtr = add;
		thisPtr->prevPtr = add;

		// �쐬�����f�[�^��thisPtr���Ȃ���
		add->nextPtr = thisPtr;
		add->prevPtr = thisPtr;
	}
	else if (temp == thisPtr->nextPtr)
	{
		// �쐬�����f�[�^��擪�ɐݒ�
		thisPtr->nextPtr = add;
		add->prevPtr = thisPtr;

		// �擪�������f�[�^�ƂȂ���
		add->nextPtr = temp;
		temp->prevPtr = add;
	}
	else if (temp == thisPtr)
	{
		// �����f�[�^�̃m�[�h���擾
		temp = thisPtr->prevPtr;

		temp->nextPtr = add;
		add->prevPtr = temp;

		thisPtr->prevPtr = add;
		add->nextPtr = thisPtr;
	}
	else if (temp == nullptr)
	{
		// �s���ȃC�e���[�^�̏ꍇ
		return false;
	}
	else
	{
		// �쐬�����f�[�^�̑O����Ȃ���
		add->nextPtr = temp;
		add->prevPtr = temp->prevPtr;

		// �쐬�����f�[�^�̑O��̃f�[�^����Ȃ���
		temp->prevPtr = add;
		add->prevPtr->nextPtr = add;
	}

	return true;
}


//------------------------------------------------------------
//�@�y �f�[�^�̑}�� �z
//�@addIterator�F�ǉ�����C�e���[�^�̏��
//�@addScore�F�ǉ�����f�[�^�̃X�R�A���
//------------------------------------------------------------
bool DoublyLinkedList::Insert(Iterator addIterator, int addScore, char* addUserName)
{
	// �f�[�^����ێ�
	int dataCount = GetDataCount();

	// �}���p�̕ϐ�
	Node* temp = addIterator.GetIteratorNode();

	// �ǉ�����f�[�^���쐬
	Node* add = new Node();
	add->recordData.score = addScore;
	add->recordData.userName = addUserName;
	
	if (dataCount == 0)
	{
		// �f�[�^���Ȃ��ꍇ�͐擪�Ɩ����ɍ쐬�����f�[�^��ݒ�

		// thisPtr�̑O����쐬�����f�[�^�ɐݒ肷��
		thisPtr->nextPtr = add;
		thisPtr->prevPtr = add;

		// �쐬�����f�[�^��thisPtr���Ȃ���
		add->nextPtr = thisPtr;
		add->prevPtr = thisPtr;
	}
	else if (temp == thisPtr->nextPtr)
	{
		// �쐬�����f�[�^��擪�ɐݒ�
		thisPtr->nextPtr = add;
		add->prevPtr = thisPtr;

		// �擪�������f�[�^�ƂȂ���
		add->nextPtr = temp;
		temp->prevPtr = add;
	}
	else if (temp == thisPtr)
	{
		// �����f�[�^�̃m�[�h���擾
		temp = thisPtr->prevPtr;

		temp->nextPtr = add;
		add->prevPtr = temp;

		thisPtr->prevPtr = add;
		add->nextPtr = thisPtr;
	}
	else if (temp == nullptr)
	{
		// �s���ȃC�e���[�^�̏ꍇ
		return false;
	}
	else
	{
		// �쐬�����f�[�^�̑O����Ȃ���
		add->nextPtr = temp;
		add->prevPtr = temp->prevPtr;

		// �쐬�����f�[�^�̑O��̃f�[�^����Ȃ���
		temp->prevPtr = add;
		add->prevPtr->nextPtr = add;
	}

	return true;
}


//------------------------------------------------------------
//�@�y �f�[�^�̍폜 �z
//�@removeIterator�F�폜����C�e���[�^�̏��
//------------------------------------------------------------
bool DoublyLinkedList::Remove(ConstIterator removeConstIterator)
{
	// �f�[�^���Ȃ����FALSE��Ԃ�
	if (GetDataCount() == 0) return false;

	// �f�[�^����̏ꍇ
	if (GetDataCount() == 1)
	{
		delete thisPtr->nextPtr;

		thisPtr->nextPtr = nullptr;
		thisPtr->prevPtr = nullptr;

		return true;
	}

	// �f�[�^����ȏ�̏ꍇ
	// �C�e���[�^�̃m�[�h���擾
	Node* temp = removeConstIterator.GetConstIteratorNode();

	if (temp == thisPtr->nextPtr)
	{
		// �擪�C�e���[�^�̏ꍇ
		thisPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = thisPtr;

		delete temp;
	}
	else if (temp == thisPtr)
	{
		// �����C�e���[�^�̏ꍇ��false��Ԃ�
		return false;
	}
	else if (temp == nullptr)
	{
		// �s���ȃC�e���[�^�̏ꍇ��false��Ԃ�
		return false;
	}
	else
	{
		// ����ȊO�̏ꍇ
		temp->prevPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = temp->prevPtr;

		delete temp;
	}

	return true;
}


//------------------------------------------------------------
//�@�y �f�[�^�̍폜 �z
//�@removeIterator�F�폜����C�e���[�^�̏��
//------------------------------------------------------------
bool DoublyLinkedList::Remove(Iterator removeIterator)
{
	// �f�[�^���Ȃ����FALSE��Ԃ�
	if (GetDataCount() == 0) return false;

	// �f�[�^����̏ꍇ
	if (GetDataCount() == 1)
	{
		delete thisPtr->nextPtr;

		thisPtr->nextPtr = nullptr;
		thisPtr->prevPtr = nullptr;

		return true;
	}

	// �f�[�^����ȏ�̏ꍇ
	// �C�e���[�^�̃m�[�h���擾
	Node* temp = removeIterator.GetIteratorNode();

	if (temp == thisPtr->nextPtr)
	{
		// �擪�C�e���[�^�̏ꍇ
		thisPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = thisPtr;

		delete temp;
	}
	else if (temp == thisPtr)
	{
		// �����C�e���[�^�̏ꍇ��false��Ԃ�
		return false;
	}
	else if (temp == nullptr)
	{
		// �s���ȃC�e���[�^�̏ꍇ��false��Ԃ�
		return false;
	}
	else
	{
		// ����ȊO�̏ꍇ
		temp->prevPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = temp->prevPtr;

		delete temp;
	}

	return true;
}


//------------------------------------------------------------
//�@�y �擪�C�e���[�^�擾 �z
//�@return�F�擪�̃C�e���[�^
//------------------------------------------------------------
DoublyLinkedList::Iterator DoublyLinkedList::GetTopIterator()
{
	// �G���[�`�F�b�N
	if (GetDataCount() == 0)
	{
		DoublyLinkedList::Iterator temp(thisPtr);

		// �f�[�^���Ȃ���΃_�~�[�m�[�h���w���C�e���[�^��Ԃ�
		return temp;
	}
	else
	{
		DoublyLinkedList::Iterator temp(thisPtr->nextPtr);

		// �擪�C�e���[�^��Ԃ�
		return temp;
	}
}


//------------------------------------------------------------
//�@�y �擪�R���X�g�C�e���[�^�擾 �z
//�@return�F�擪�R���X�g�C�e���[�^
//------------------------------------------------------------
DoublyLinkedList::ConstIterator DoublyLinkedList::GetTopConstIterator() const
{
	// �G���[�`�F�b�N
	if (GetDataCount() == 0)
	{
		DoublyLinkedList::ConstIterator temp(thisPtr);

		// �f�[�^���Ȃ���΃_�~�[�m�[�h���w���C�e���[�^��Ԃ�
		return temp;
	}
	else
	{
		DoublyLinkedList::ConstIterator temp(thisPtr->nextPtr);

		// �擪�C�e���[�^��Ԃ�
		return temp;
	}
}


//------------------------------------------------------------
//�@�y �����C�e���[�^�擾 �z
//�@return�F�����C�e���[�^
//------------------------------------------------------------
DoublyLinkedList::Iterator DoublyLinkedList::GetEndIterator()
{
	DoublyLinkedList::Iterator temp(thisPtr);

	// �����C�e���[�^��Ԃ�
	return temp;
}


//------------------------------------------------------------
//�@�y �����R���X�g�C�e���[�^�擾 �z
//�@return�F�����R���X�g�C�e���[�^
//------------------------------------------------------------
DoublyLinkedList::ConstIterator DoublyLinkedList::GetEndConstIterator() const
{
	DoublyLinkedList::ConstIterator temp(thisPtr);

	// �����C�e���[�^��Ԃ�
	return temp;
}
