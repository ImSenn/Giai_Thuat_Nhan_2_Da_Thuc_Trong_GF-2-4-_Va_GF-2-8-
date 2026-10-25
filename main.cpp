#include <iostream>
#include <vector>

using namespace std;

// Hàm in đa thức ra màn hình dạng x^k
void in_da_thuc(const vector<int>& a) {
    bool co_so_hang = false;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == 1) {
            if (co_so_hang) cout << " + ";
            if (i == 0) cout << "1";
            else if (i == 1) cout << "x";
            else cout << "x^" << i;
            co_so_hang = true;
        }
    }
    if (!co_so_hang) cout << "0";
}

// Hàm nhân 2 đa thức trong trường hữu hạn với đa thức tối giản P
vector<int> nhan_da_thuc(vector<int> A, vector<int> B, vector<int> P) {
    int bac_A = A.size() - 1;
    int bac_B = B.size() - 1;
    int bac_tich = bac_A + bac_B;

    vector<int> C(bac_tich + 1, 0);

    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)B.size(); j++) {
            int tich_he_so = A[i] * B[j];
            C[i + j] = (C[i + j] + tich_he_so) % 2;
        }
    }

    cout << "Tích sau khi nhân phân phối: ";
    in_da_thuc(C);
    cout << "\n";

    int bac_P = P.size() - 1;

    while (true) { 
        while (!C.empty() && C.back() == 0) {
            C.pop_back();
        }

        int bac_C = (int)C.size() - 1;
        if (bac_C < bac_P) {
            break;
        }

        int lech_bac = bac_C - bac_P;

        for (int k = 0; k < (int)P.size(); k++) {
            C[k + lech_bac] = (C[k + lech_bac] + P[k]) % 2;
        }
    }

    if (C.empty()) {
        C.push_back(0);
    }

    return C;
}

int main() {
    cout << "GF(2^4)"<< "\n";
    vector<int> P4 = {1, 1, 0, 0, 1};
    vector<int> A4 = {1, 1, 0, 1};
    vector<int> B4 = {1, 0, 1};

    cout<<"A(x) = "; in_da_thuc(A4); cout<<"\n";
    cout<<"B(x) = "; in_da_thuc(B4); cout<<"\n";
    cout<<"P(x) = "; in_da_thuc(P4); cout<<"\n";

    vector<int> KQ4 = nhan_da_thuc(A4, B4, P4);
    cout<<"Kết quả "; in_da_thuc(KQ4); cout<<"\n\n";

    cout<<"GF(2^8)"<<"\n";
    vector<int> P8 = {1, 1, 0, 1, 1, 0, 0, 0, 1};

    vector<int> A8 = {1, 1, 1, 0, 1, 0, 1, 0};
    vector<int> B8 = {1, 1, 0, 0, 0, 0, 0, 1};

    cout<<"A(x) = "; in_da_thuc(A8); cout<<" (0x57)\n";
    cout<<"B(x) = "; in_da_thuc(B8); cout<<" (0x83)\n";
    cout<<"P(x) = "; in_da_thuc(P8); cout<<"\n";

    vector<int> KQ8 = nhan_da_thuc(A8, B8, P8);
    cout<<"Kết quả"; in_da_thuc(KQ8); cout<<"\n";

    int val_hex = 0;
    for (int i = 0; i < (int)KQ8.size(); i++) {
        val_hex += KQ8[i] * (1 << i);
    }
    cout<<"Giá trị Hex: 0x"<<hex<<val_hex<<dec;

    return 0;
}

