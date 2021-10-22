//============================================================
//
//  title  : GoogleTest�蓮�e�X�g�R�[�h�̒�`�A�錾 [test.h]
//  Author : ���c �z��
//   Date  : 2021/10/11
//  Update : 2021/10/22
//
//============================================================
//#pragma once
#include "gtest/gtest.h"
#include "../DoublyLinkedList/doublyLinkedList.h"


//--------------------------------------------------------------------------------
// �}�N����`
//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g(���X�g)

// �Z�f�[�^���̎擾�̃}�N���Z
// const�̃��\�b�h�ł��邩�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�ΐ����ł�
//#define TT_TEST_DATA_IS_CONST

// �Z�f�[�^�̑}���̃}�N���Z
// ��const�̃��\�b�h�ł��邩�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł�
//#define TT_TEST_DATA_INSERT_IS_NO_CONST

// �Z�f�[�^�̍폜�̃}�N���Z
// ��const�̃��\�b�h�ł��邩�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł�
//#define TT_TEST_DATA_REMOVE_IS_NO_CONST

// �Z�擪�C�e���[�^�̎擾�̃}�N���Z
// const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł�
//#define TT_TEST_CONSTLIST_GET_TOPITERATOR

// �Z�擪�R���X�g�C�e���[�^�̎擾�̃}�N���Z
// const�̃��\�b�h�ł��邩�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�ΐ����ł�
//#define TT_TEST_CONSTLIST_GET_TOPCONSTITERATOR

// �Z�����C�e���[�^�̎擾�̃}�N���Z
// const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł�
//#define TT_TEST_CONSTLIST_GET_ENDITERATOR

// �Z�����R���X�g�C�e���[�^�̎擾�̃}�N���Z
// const�̃��\�b�h�ł��邩�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�ΐ����ł�
//#define TT_TEST_CONSTLIST_GET_ENDCONSTITERATOR

// �Z�C�e���[�^�̎w���v�f���擾�̃}�N���Z
// ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł�
//#define TT_TEST_GET_CONSTITERATOR_SUBSTITUTION

// �Z�C�e���[�^�̃R�s�[���s���Z
// ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł�
//#define TT_TEST_ITERATOR_COPY

// �Z�C�e���[�^�̑�����s���Z
// Iterator��ConstIterator�����ł��Ȃ������`�F�b�N�i�蓮�m�F�j
// ���L���ɂ��ăR���p�C�����ʂ�Ȃ���ΐ����ł�
//#define TT_TEST_ITERATOR_SUBSTITUTION