//============================================================
//
//  title  : データ管理 [DataManager.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/19
//  Update : 2021/10/22
//
//============================================================
#pragma once
#define _CRT_SECURE_NO_WARNINGS


//============================================================
//　インクルード
//============================================================
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include "DataManager.h"


//============================================================
//　変数宣言
//============================================================
DoublyLinkedList DataManager::scoresList;


//============================================================
//　関数
//============================================================
//------------------------------------------------------------
//　コンストラクタ
//------------------------------------------------------------
DataManager::DataManager()
{
	;
}


//------------------------------------------------------------
//　デストラクタ
//------------------------------------------------------------
DataManager::~DataManager()
{
	;
}


//------------------------------------------------------------
//　データを表示
//------------------------------------------------------------
void DataManager::DispData()
{
	// 表示用の変数
	int datacount = scoresList.GetDataCount();

	// エラーチェック
	if (datacount == 0)
	{
		std::cout << "データがありません。" << std::endl;
		return;
	}

	// データを表示
	// 先頭イテレータを取得
	DoublyLinkedList::Iterator it = scoresList.GetTopIterator();

	for (int i = 0; i < datacount; i++)
	{
		// データを表示
		std::cout << "スコア：" << it.GetData().score << "　" << "ユーザー名：" << it.GetData().userName << std::endl;
		
		// イテレータをインクリメント
		it++;
	}
}


//------------------------------------------------------------
//　Scoresテキストファイルの読み込み
//------------------------------------------------------------
void DataManager::ReadScoreTextFile()
{
	// ファイル名を代入
	const char *fileName = "Scores.txt";

	// 代入用の変数
	std::string score;
	//std::string userName;
	char userName[16] = {};
	char temp[4] = {};
	DoublyLinkedList::Iterator it;

	// ファイルを開く
	FILE* fp = fopen(fileName, "r");

	// データ数によって変わるような仕様にする
	// 100の部分を修正予定
	for (int i = 0; i < 100; i++)
	{
		// 全角スペースまでの文字を取得
		while ((temp[0] = fgetc(fp)) != '\t')
		{
			score += temp;
		}

		// 改行までの文字を取得
		while ((temp[0] = fgetc(fp)) != '\n')
		{
			//userName += temp;
			strcat(userName, temp);
		}
		
		// 末尾イテレータを取得
		it = scoresList.GetEndIterator();

		// リストに追加
		scoresList.Insert(it, atoi(score.c_str()), userName);

		// 初期化
		score = "";
		for (int i = 0; i < 16; i++)
		{
			userName[i] = NULL;
		}
	}
}
