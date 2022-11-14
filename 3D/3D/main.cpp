#include "MuSoenMath.h"

int main() {
    vec3 v(new float[3]{ 1, 1, 1 }); // v(1, 1, 1)

    mat3 Translate(new float[3][3]{
       { 1, 0, 0 },
       { 0, 1, 0 },
       { 3, 5, 1 }
        });

    mat3 Rotate(new float[3][3]{
       { (float)cos(PI / 6), -(float)sin(PI / 6), 0}, // (PI/6)라디안 = (30)도
       { (float)sin(PI / 6), (float)cos(PI / 6), 0},
       { 0, 0, 1 }
        });

    mat3 Scale(new float[3][3]{
       { 2, 0, 0 },
       { 0, 2, 0 },
       { 0, 0, 1 }
        });

    vec3 p(new float[3]{ 0, 0, 0 }); // p(0, 0, 0)

    p = v * Translate * Rotate * Scale; // 좌표 v를 (3,5 이동 | 30도 회전 | 2배 확대)한 후 좌표 p에 저장

    cout << "x: " << p.v[0] << endl;
    cout << "y: " << p.v[1] << endl;
    cout << endl;

    mat3 Identity(new float[3][3]{ // 3*3행렬 Identity 생성
       { 6, 3, 1 },
       { 4, 2, 6 },
       { 1, 5, 2 }
        });

    Identity.identity_matrix(); // 단위 행렬 초기화 함수

    cout << "단위행렬" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Identity.m[i][j];
        }
        cout << endl;
    }

    cout << endl;

    mat3 Transpose(new float[3][3]{ // 3*3행렬 Transpose 생성
       { 6, 2, 5 },
       { 9, 4, 8 },
       { 2, 1, 4 }
        });

    Transpose.Transpose();

    cout << "전치행렬" << endl;

    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) {
            cout << Transpose.m[i][j];
        }
        cout << endl;
    }

    cout << endl;

    mat3 Plus(new float[3][3]{ // 3*3행렬 Plus 생성
        { 3, 3, 3 },
        { 2, 2, 2 },
        { 1, 1, 1 }
        });

    cout << "행렬 덧셈" << endl;

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

    mat3 Sub(new float[3][3]{ // 3*3행렬 Sub 생성
        { 3, 3, 3 },
        { 2, 2, 2 },
        { 1, 1, 1 }
        });

    cout << "행렬 뺄셈" << endl;

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

    mat3 Multiply(new float[3][3]{ // 3*3행렬 Multiply 생성
       { 3, 3, 3 },
       { 2, 2, 2 },
       { 1, 1, 1 }
        });

    cout << "행렬 곱" << endl;

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

    cout << "행렬 곱 전치" << endl;
    mat3 Multiply_transpose_matrix(new float[3][3]{ // 3*3행렬
        { 3, 3, 3 },
        { 2, 2, 2 },
        { 1, 1, 1 }
        });
    
    Multiply_transpose_matrix.multiply_transpose_matrix(new float[3][3]{ //2만큼 행렬에 곱함
        { 2, 2, 2 },
        { 2, 2, 2 },
        { 2, 2, 2 }
        });

    for (int i = 0; i < 3; i++) { //2만큼 곱한 행렬을 전치
        for (int j = 0; j < 3; j++) {
            cout << Multiply_transpose_matrix.m[i][j];
        }
        cout << endl;
    }

    cout << endl;


    cout << "벡터 곱" << endl;
    vec3 VMultiply_vector(new float[3]{1,2,3});

    VMultiply_vector.multiply_vector(2);

    for (int i = 0; i < 3; i++) {
        cout << VMultiply_vector.v[i];
        cout << endl;

    }

    cout << endl;

    Number NUM(4.0);
    cout << "상수 곱셈" << endl;
    NUM.NumMultiply(2.0);
    cout << NUM.num << endl;

    cout << endl;

    cout << "상수 나눗셈" << endl;
    NUM.NumDivision(2.0);
    cout << NUM.num << endl;
}
