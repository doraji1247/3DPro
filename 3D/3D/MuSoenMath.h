#include <iostream>
#include <math.h>

#define PI 3.14159
using namespace std;

class mat3 {
public:
    float m[3][3]; // 3*3 ���
    mat3(float mat3[3][3]); // ������
    
    mat3 identity_matrix(); // ������� �ʱ�ȭ �Լ�
    mat3 Transpose(); // ��ġ��� �Լ�

    mat3 sub_matrix(const mat3& ref); //��� ����
    mat3 plus_matrix(const mat3& ref); //��� ����
    mat3 multiply_matrix(const mat3& ref); //��� ����
    mat3 multiply_transpose_matrix(const mat3& ref); //��� �� ��ġ

    mat3 operator*(mat3& ref); // �����ε� �Լ�
 
};

mat3::mat3(float mat3[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m[i][j] = mat3[i][j]; // mat3 Ŭ������ m�� Ŭ���� ������ �Է��� ��� ����
        }
    }
}

mat3 mat3::identity_matrix() { //������� �ʱ�ȭ �Լ�
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) this->m[i][j] = 1; // i�� j�� ���� ��� 1 �Է�
            else this->m[i][j] = 0; // i�� j�� ���� ��� 1 �Է�
        }
    }

    for (int i = 0; i < 3; i++) { // ���� ��� ���
        for (int j = 0; j < 3; j++) {

        }
    }

    return *this;
}

mat3 mat3::Transpose() { //��ġ��� �Լ�
    mat3 result(new float[3][3]{ {1, 0, 0}, {0, 1, 0}, {0, 0, 1} });

    for (int i = 0; i < 3; i++) // ��� ����
        for (int j = 0; j < 3; j++)
            result.m[i][j] = this->m[i][j];

    for (int i = 0; i < 3; i++) // ��ġ
        for (int j = 0; j < 3; j++)
            this->m[j][i] = result.m[i][j];

    return *this;
}

mat3 mat3::operator*(mat3& ref) {
    mat3 result(new float[3][3]{ {1, 0, 0}, {0, 1, 0}, {0, 0, 1} });

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++)
                result.m[i][j] += (m[k][j] * ref.m[i][k]); // 3*3 ��� �� ����
        }
    }

    return result;
}

mat3 mat3::plus_matrix(const mat3& ref) { // mat3 ���� ���� �Լ�
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] += ref.m[i][j]; // 33 ��� ���� ����
        }
    }

    return *this;
}

mat3 mat3::sub_matrix(const mat3& ref) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] -= ref.m[i][j]; // 33 ��� ���� ����
        }
    }

    return *this;
}

mat3 mat3::multiply_matrix(const mat3& ref) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] *= ref.m[i][j]; // 33 ��� �� ����
        }
    }

    return *this;
}

mat3 mat3::multiply_transpose_matrix(const mat3& ref) { // mat3 �� ��ġ ���� �Լ�
    mat3 temporary(new float[3][3]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] *= ref.m[i][j]; // 3*3 ��� ���� ����
        }
    }

    for (int i = 0; i < 3; i++) // ��� ����
        for (int j = 0; j < 3; j++)
            temporary.m[i][j] = m[i][j];

    for (int i = 0; i < 3; i++) // ��ġ
        for (int j = 0; j < 3; j++)
            m[j][i] = temporary.m[i][j];

    return *this;
}

class vec3
{
public:
    float v[3]; // { x, y, z }
    vec3(float vec3[3]); // ������
    float v1[3];

    vec3 multiply_vector(float ref); // ���� ��
    vec3 operator*(const mat3& ref); // �����ε� �Լ�
};

vec3::vec3(float vec3[3]) {
    for (int i = 0; i < 3; i++) {
        this->v[i] = vec3[i]; // vec3 Ŭ������ v�� Ŭ���� ������ �Է��� ��ǥ ����
    }
}

vec3 vec3::multiply_vector(float ref) { // (x, y, z) * (float) ����
    for (int i = 0; i < 3; i++)
        v[i] *= ref;

    return *this;
}

vec3 vec3::operator*(const mat3& ref)
{
    vec3 result(new float[3]{ 0, 0, 0 });

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.v[i] += (v[j] * ref.m[j][i]); // (x, y, z) * (3*3) ��� ����
        }
    }

    return result;
}

class Number
{
public:
    float num;
    Number(float num);//������

    Number NumMultiply(float Num); //��� ����
    Number NumDivision(float Num); //��� ������
};

Number::Number(float num) {
    this->num = num;
}

Number Number::NumMultiply(float Num)
{
    num *= Num;

    return *this;
}

Number Number::NumDivision(float Num) {
    num /= Num;

    return *this;
}
