#pragma once

#include <iostream>
#include <math.h>

using namespace std;

namespace MSM
{
	class vec3 //클래스 vec3 선언
	{
	public:
		int Vec3[3][3]; //3*3 행렬 선언

		void vector(int x, int y) //(3, 1) 좌표를 받기 위한 함수 생성
		{
			Vec3[0][0] = x;
			Vec3[1][1] = y;
		}

		void RSVET() //3*3 행렬 초기화 함수 생성
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Vec3[i][j] = 0;
					if (i == j)
					{
						Vec3[i][j] = 1;
					}
				}
			}
		}

	};

	class mat3 
	{
		public:
			int TL[3][3]; //translate 값을 저장하기 위해 선언
			double RT[3][3]; //rotate 값을 저장하기 위해 선언
			int SC[3][3]; //scal 값을 저장하기 위해 선언

			void RStranslate(int x, int y) //(3, 5) 이동하는 값을 받기 위한 함수 생성
			{
				TL[2][0] = x;
				TL[2][1] = y;
			}

			void Translate() //translate 값 초기화 함수 생성
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						TL[i][j] = 0;
						if (i == j)
						{
							TL[i][j] = 1;
						}
					}
				}

			}

			void RSrotate(int x) //30도 회전하는 값을 받기 위한 함수 생성
			{
				SC[0][0] = cos(x);
				SC[0][1] = -sin(x);
				SC[1][0] = sin(x);
				SC[1][1] = cos(x);
			}

			void Rotate() //rotate 값 초기화 함수 생성
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						RT[i][j] = 0;
						if (i == j)
						{
							RT[i][j] = 1;
						}
					}
				}
			}

			void RSscal(int x) //2배 확대되는 값을 받기 위한 함수 생성
			{
				SC[0][0] = x;
				SC[1][1] = x;
			}

			void Scal() //scal 값 초기화 함수 생성
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						SC[i][j] = 0;
						if (i == j)
						{
							SC[i][j] = 1;
						}
					}
				}
			}

			double multiply(int ver[3][3], int tran[3][3], double Rot[3][3], int Sca[3][3]) //행렬을 곱하는 함수 (ver * tran * Rot * Scal)
			{
				double a[3][3] = { 0 }; // ver과 tran 곱한 값을 a에 저장
				double b[3][3] = { 0 }; //a와 Rot 곱한 값을 b에 저장
				double c[3][3] = { 0 }; //b와 Scal 곱한 값을 c에 저장 및 결과 출력


				for (int i = 0; i < 3; i++) //vec3와 translate를 곱함
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 3; k++)
						{
							a[i][j] += ver[i][k] * tran[k][j];
						}
					}
				}

				for (int i = 0; i < 3; i++) //a와 rotate를 곱함
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 3; k++)
						{
							b[i][j] += a[i][k] * Rot[k][j];
						}
					}
				}

				for (int i = 0; i < 3; i++) //b와 Scal를 곱함
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 3; k++)
						{
							c[i][j] += b[i][k] * Sca[k][j];
						}
					}
				}

				for (int i = 0; i < 3; i++) //행렬 출력
				{
					for (int k = 0; k < 3; k++)
					{

						cout << c[i][k];
						cout << ' ';
					}
					cout << endl;
				}

				return 0;
			}
	};
}