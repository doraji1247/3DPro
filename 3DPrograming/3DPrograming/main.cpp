#include "MuSoenMath.h"

void main() 
{
	MSM::vec3 V; //MuSoenMath.h 헤더파일에 있는 vec3를 사용
	MSM::mat3 M; //MuSoenMath.h 헤더파일에 있는 mat3를 사용
	
	V.RSVET(); //vec3 값 초기화
	V.vector(3, 1); //(3, 1) 좌표 값 입력

	M.Translate(); //translate 값 초기화
	M.Rotate(); //rotate 값 초기화
	M.Scal(); //scal 값 초기화

	M.RStranslate(3,5); //(3, 5)로 이동 [2][0] = 3, [2][1] = 5
	M.RSrotate(30); //30도 회전 [0][0] = cos(30), [0][1] = -sin(30), [1][0] = sin(30), [1][1] = cos(30)
	M.RSscal(2); //2배 확대 [0][0] = 2 [1][1] = 2

	M.multiply(V.Vec3, M.TL, M.RT, M.SC); //vec, translate, rotate, scal 행렬들을 순서대로 곱하는 함수

}
