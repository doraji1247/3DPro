#include "MuSoenMath.h"

int main() {
    vec3 v(new float[3]{ 1, 1, 1 }); // v(1, 1, 1)

    mat3 Translate(new float[3][3]{
       { 1, 0, 0 },
       { 0, 1, 0 },
       { 3, 5, 1 }
        });

    mat3 Rotate(new float[3][3]{
       { (float)cos(PI / 6), -(float)sin(PI / 6), 0}, // (PI/6)���� = (30)��
       { (float)sin(PI / 6), (float)cos(PI / 6), 0},
       { 0, 0, 1 }
        });

    mat3 Scale(new float[3][3]{
       { 2, 0, 0 },
       { 0, 2, 0 },
       { 0, 0, 1 }
        });

    vec3 p(new float[3]{ 0, 0, 0 }); // p(0, 0, 0)

    p = v * Translate * Rotate * Scale; // ��ǥ v�� (3,5 �̵� | 30�� ȸ�� | 2�� Ȯ��)�� �� ��ǥ p�� ����

    cout << "x: " << p.v[0] << endl;
    cout << "y: " << p.v[1] << endl;
    cout << endl;

    mat3 Identity(new float[3][3]{ // 3*3��� Identity ����
       { 6, 3, 1 },
       { 4, 2, 6 },
       { 1, 5, 2 }
        });

    Identity.identity_matrix(); // ���� ��� �ʱ�ȭ �Լ�

    cout << "�������" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Identity.m[i][j];
        }
        cout << endl;
    }

    cout << endl;

    mat3 Transpose(new float[3][3]{ // 3*3��� Transpose ����
       { 6, 2, 5 },
       { 9, 4, 8 },
       { 2, 1, 4 }
        });

    Transpose.Transpose();

    cout << "��ġ���" << endl;

    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) {
            cout << Transpose.m[i][j];
        }
        cout << endl;
    }

    cout << endl;

    mat3 Plus(new float[3][3]{ // 3*3��� Plus ����
        { 3, 3, 3 },
        { 2, 2, 2 },
        { 1, 1, 1 }
        });

    cout << "��� ����" << endl;

    Plus.plus_matrix(new float[3][3]{
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 }
        });

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Plus.m[i][j];
        }
        cout << endl;
    }

    cout << endl;

    mat3 Sub(new float[3][3]{ // 3*3��� Sub ����
        { 3, 3, 3 },
        { 2, 2, 2 },
        { 1, 1, 1 }
        });

    cout << "��� ����" << endl;

    Sub.sub_matrix(new float[3][3]{
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 }
        });
        
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Sub.m[i][j];
        }
        cout << endl;
    }
    
    cout << endl;

    mat3 Multiply(new float[3][3]{ // 3*3��� Multiply ����
       { 3, 3, 3 },
       { 2, 2, 2 },
       { 1, 1, 1 }
        });

    cout << "��� ��" << endl;

    Multiply.multiply_matrix(new float[3][3]{
        { 2, 2, 2 },
        { 2, 2, 2 },
        { 2, 2, 2 }
        });

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Multiply.m[i][j];
        }
        cout << endl;
    }

    cout << endl;

    cout << "��� �� ��ġ" << endl;
    mat3 Multiply_transpose_matrix(new float[3][3]{ // 3*3���
        { 3, 3, 3 },
        { 2, 2, 2 },
        { 1, 1, 1 }
        });
    
    Multiply_transpose_matrix.multiply_transpose_matrix(new float[3][3]{ //2��ŭ ��Ŀ� ����
        { 2, 2, 2 },
        { 2, 2, 2 },
        { 2, 2, 2 }
        });

    for (int i = 0; i < 3; i++) { //2��ŭ ���� ����� ��ġ
        for (int j = 0; j < 3; j++) {
            cout << Multiply_transpose_matrix.m[i][j];
        }
        cout << endl;
    }

    cout << endl;


    cout << "���� ��" << endl;
    vec3 VMultiply_vector(new float[3]{1,2,3});

    VMultiply_vector.multiply_vector(2);

    for (int i = 0; i < 3; i++) {
        cout << VMultiply_vector.v[i];
        cout << endl;

    }

    cout << endl;

    Number NUM(4.0);
    cout << "��� ����" << endl;
    NUM.NumMultiply(2.0);
    cout << NUM.num << endl;

    cout << endl;

    cout << "��� ������" << endl;
    NUM.NumDivision(2.0);
    cout << NUM.num << endl;
}
