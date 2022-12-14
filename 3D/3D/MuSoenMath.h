#include <iostream>
#include <math.h>

#define PI 3.14159
using namespace std;

class mat3 {
public:
    float m[3][3]; // 3*3 행렬
    mat3(float mat3[3][3]); // 생성자
    mat3();

    mat3 identity_matrix(); // 단위행렬 초기화 함수
    mat3 Transpose(); // 전치행렬 함수

    mat3 sub_matrix(const mat3& ref); //행렬 뺄셈
    mat3 plus_matrix(const mat3& ref); //행렬 덧셈
    mat3 multiply_matrix(const mat3& ref); //행렬 곱셈
    mat3 multiply_transpose_matrix(const mat3& ref); //행렬 곱 전치

    mat3 operator*(mat3& ref); // 오버로딩 함수
 
};

mat3::mat3(){}

mat3::mat3(float mat3[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m[i][j] = mat3[i][j]; // mat3 클래스의 m에 클래스 생성시 입력한 행렬 저장
        }
    }
}

mat3 mat3::identity_matrix() { //단위행렬 초기화 함수
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) this->m[i][j] = 1; // i와 j가 같을 경우 1 입력
            else this->m[i][j] = 0; // i와 j가 같을 경우 1 입력
        }
    }

    for (int i = 0; i < 3; i++) { // 단위 행렬 출력
        for (int j = 0; j < 3; j++) {

        }
    }

    return *this;
}

mat3 mat3::Transpose() { //전치행렬 함수
    mat3 result(new float[3][3]{ {1, 0, 0}, {0, 1, 0}, {0, 0, 1} });

    for (int i = 0; i < 3; i++) // 행렬 복사
        for (int j = 0; j < 3; j++)
            result.m[i][j] = this->m[i][j];

    for (int i = 0; i < 3; i++) // 전치
        for (int j = 0; j < 3; j++)
            this->m[j][i] = result.m[i][j];

    return *this;
}

mat3 mat3::operator*(mat3& ref) {
    mat3 result(new float[3][3]{ {1, 0, 0}, {0, 1, 0}, {0, 0, 1} });

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++)
                result.m[i][j] += (m[k][j] * ref.m[i][k]); // 3*3 행렬 곱 연산
        }
    }

    return result;
}

mat3 mat3::plus_matrix(const mat3& ref) { // mat3 덧셈 연산 함수
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] += ref.m[i][j]; // 33 행렬 덧셈 연산
        }
    }

    return *this;
}

mat3 mat3::sub_matrix(const mat3& ref) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] -= ref.m[i][j]; // 33 행렬 뺄셈 연산
        }
    }

    return *this;
}

mat3 mat3::multiply_matrix(const mat3& ref) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] *= ref.m[i][j]; // 33 행렬 곱 연산
        }
    }

    return *this;
}

mat3 mat3::multiply_transpose_matrix(const mat3& ref) { // mat3 곱 전치 연산 함수
    mat3 temporary(new float[3][3]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] *= ref.m[i][j]; // 3*3 행렬 곱셈 연산
        }
    }

    for (int i = 0; i < 3; i++) // 행렬 복사
        for (int j = 0; j < 3; j++)
            temporary.m[i][j] = m[i][j];

    for (int i = 0; i < 3; i++) // 전치
        for (int j = 0; j < 3; j++)
            m[j][i] = temporary.m[i][j];

    return *this;
}

class vec3
{
public:
    float v[3]; // { x, y, z }
    vec3(float vec3[3]); // 생성자

    vec3();
    float v1[3];

    vec3 multiply_vector(float ref); // 벡터 곱
    vec3 operator*(const mat3& ref); // 오버로딩 함수
};

vec3::vec3(){}

vec3::vec3(float vec3[3]) {
    for (int i = 0; i < 3; i++) {
        this->v[i] = vec3[i]; // vec3 클래스의 v에 클래스 생성시 입력한 좌표 저장
    }
}

vec3 vec3::multiply_vector(float ref) { // (x, y, z) * (float) 연산
    for (int i = 0; i < 3; i++)
        v[i] *= ref;

    return *this;
}

// mat3 * vec3 연산자
vec3 operator*(const mat3& m, const vec3& v)
{
    vec3 result(new float[3]{ 0, 0, 0 });

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.v[i] += (m.m[j][i] * v.v[j]);
        }
    }

    //result.v[0] = m.m[0][0] * v.v[0] + m.m[1][0] * v.v[1] + m.m[2][0] * v.v[2];
    //result.v[1] = m.m[0][1] * v.v[0] + m.m[1][1] * v.v[1] + m.m[2][1] * v.v[2];
    //result.v[2] = m.m[0][2] * v.v[0] + m.m[1][2] * v.v[1] + m.m[2][2] * v.v[2];

    return result;
}

vec3 vec3::operator*(const mat3& ref)
{
    vec3 result(new float[3]{ 0, 0, 0 });

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.v[i] += (v[j] * ref.m[j][i]); // (x, y, z) * (3*3) 행렬 연산
        }
    }

    return result;
}

//class Number
//{
//public:
//    float num;
//    Number(float num);//생성자
//
//    Number NumMultiply(float Num); //상수 곱셈
//    Number NumDivision(float Num); //상수 나눗셈
//};
//
//Number::Number(float num) {
//    this->num = num;
//}
//
//Number Number::NumMultiply(float Num)
//{
//    num *= Num;
//
//    return *this;
//}
//
//Number Number::NumDivision(float Num) {
//    num /= Num;
//
//    return *this;
//}