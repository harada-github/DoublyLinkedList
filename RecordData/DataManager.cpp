//============================================================
//
//  title  : �f�[�^�Ǘ� [DataManager.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/19
//  Update : 2021/10/22
//
//============================================================
#pragma once
#define _CRT_SECURE_NO_WARNINGS


//============================================================
//�@�C���N���[�h
//============================================================
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include "DataManager.h"


//============================================================
//�@�ϐ��錾
//============================================================
DoublyLinkedList DataManager::scoresList;


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@�R���X�g���N�^
//------------------------------------------------------------
DataManager::DataManager()
{
	;
}


//------------------------------------------------------------
//�@�f�X�g���N�^
//------------------------------------------------------------
DataManager::~DataManager()
{
	;
}


//------------------------------------------------------------
//�@�f�[�^��\��
//------------------------------------------------------------
void DataManager::DispData()
{
	// �\���p�̕ϐ�
	int datacount = scoresList.GetDataCount();

	// �G���[�`�F�b�N
	if (datacount == 0)
	{
		std::cout << "�f�[�^������܂���B" << std::endl;
		return;
	}

	// �f�[�^��\��
	// �擪�C�e���[�^���擾
	DoublyLinkedList::Iterator it = scoresList.GetTopIterator();

	for (int i = 0; i < datacount; i++)
	{
		// �f�[�^��\��
		std::cout << "�X�R�A�F" << it.GetData().score << "�@" << "���[�U�[���F" << it.GetData().userName << std::endl;
		
		// �C�e���[�^���C���N�������g
		it++;
	}
}


//------------------------------------------------------------
//�@Scores�e�L�X�g�t�@�C���̓ǂݍ���
//------------------------------------------------------------
void DataManager::ReadScoreTextFile()
{
	// �t�@�C��������
	const char *fileName = "Scores.txt";

	// ����p�̕ϐ�
	std::string score;
	//std::string userName;
	char userName[16] = {};
	char temp[4] = {};
	DoublyLinkedList::Iterator it;

	// �t�@�C�����J��
	FILE* fp = fopen(fileName, "r");

	// �f�[�^���ɂ���ĕς��悤�Ȏd�l�ɂ���
	// 100�̕������C���\��
	for (int i = 0; i < 100; i++)
	{
		// �S�p�X�y�[�X�܂ł̕������擾
		while ((temp[0] = fgetc(fp)) != '\t')
		{
			score += temp;
		}

		// ���s�܂ł̕������擾
		while ((temp[0] = fgetc(fp)) != '\n')
		{
			//userName += temp;
			strcat(userName, temp);
		}
		
		// �����C�e���[�^���擾
		it = scoresList.GetEndIterator();

		// ���X�g�ɒǉ�
		scoresList.Insert(it, atoi(score.c_str()), userName);

		// ������
		score = "";
		for (int i = 0; i < 16; i++)
		{
			userName[i] = NULL;
		}
	}
}
