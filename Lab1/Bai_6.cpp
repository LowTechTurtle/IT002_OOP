#include <bits/stdc++.h>
using namespace std;

// trong bai nay, mang A se la mang con va ta can tim so lan xuat hien 
// cua mang A trong mang B

// Ham dung de tinh Longest Proper Prefix voi pat( viet tat cho pattern)
// la mang A da nhap vao
void computeLPSArray(vector<int> pat, int M, vector<int>& lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Ham thuc hien search cho cac lan xuat hien cua A trong B
// pat( pattern) la mang A, txt( text) chinh la mang B
vector<int> KMPSearch(vector<int> pat, vector<int> txt)
{
    int M = pat.size();
    int N = txt.size();
    vector<int> lps(M);
    vector<int> result;

    computeLPSArray(pat, M, lps);

    int i = 0; 
    int j = 0; 

    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            result.push_back(i - j + 1);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return result;
}

int main()
{
    vector<int> pat;
    vector<int> txt;
    int n, m, temp;
    cin >> n >> m; 

    for (int i = 0; i < n; i++) {
        cin >> temp;
        pat.push_back(temp);
    }
    
    for (int i = 0; i < m; i++) {
        cin >> temp;
        txt.push_back(temp);
    } 

    vector<int> result = KMPSearch(pat, txt);


    cout << "So lan mang A xuat hien trong mang B la: " << result.size() << endl;
    if (result.size() > 0)
        cout << "Cac vi tri ma mang A xuat hien trong mang B la: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}