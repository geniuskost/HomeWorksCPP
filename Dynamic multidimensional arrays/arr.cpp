#include <iostream>
#include <vector>


using namespace std;

void printMat(const vector<vector<int>>& m){
    for(size_t i=0;i<m.size();++i){
        for(size_t j=0;j<m[i].size();++j) cout<<m[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

void addColumn(vector<vector<int>>& mat,int pos,int defaultValue=0){
    if(mat.empty()) return;
    int cols = (int)mat[0].size();
    if(pos<0) pos=0;
    if(pos>cols) pos=cols;
    for(size_t r=0;r<mat.size();++r) mat[r].insert(mat[r].begin()+pos,defaultValue);
}

void removeColumn(vector<vector<int>>& mat,int pos){
    if(mat.empty()) return;
    int cols = (int)mat[0].size();
    if(pos<0 || pos>=cols) return;
    for(size_t r=0;r<mat.size();++r) mat[r].erase(mat[r].begin()+pos);
}

void cyclicShiftRowsCols(vector<vector<int>>& mat,int rowShift,int colShift){
    if(mat.empty()) return;
    int rows=(int)mat.size();
    int cols=(int)mat[0].size();
    if(rows==0 || cols==0) return;
    rowShift = ((rowShift%rows)+rows)%rows;
    colShift = ((colShift%cols)+cols)%cols;
    if(rowShift!=0){
        vector<vector<int>> tmp(rows);
        for(int r=0;r<rows;++r) tmp[(r+rowShift)%rows]=mat[r];
        mat=tmp;
    }
    if(colShift!=0){
        for(int r=0;r<rows;++r){
            vector<int> old = mat[r];
            vector<int> nw(cols);
            for(int c=0;c<cols;++c) nw[(c+colShift)%cols]=old[c];
            mat[r]=nw;
        }
    }
}

vector<vector<int>> transpose(const vector<vector<int>>& mat){
    if(mat.empty()) return {};
    int rows=(int)mat.size();
    int cols=(int)mat[0].size();
    vector<vector<int>> res(cols,vector<int>(rows));
    for(int r=0;r<rows;++r) for(int c=0;c<cols;++c) res[c][r]=mat[r][c];
    return res;
}

vector<int> flatten(const vector<vector<int>>& m){
    vector<int> out;
    for(size_t i=0;i<m.size();++i) for(size_t j=0;j<m[i].size();++j) out.push_back(m[i][j]);
    return out;
}

vector<int> uniq(const vector<int>& v){
    vector<int> out;
    for(size_t i=0;i<v.size();++i){
        bool found=false;
        for(size_t j=0;j<out.size();++j) if(out[j]==v[i]){ found=true; break; }
        if(!found) out.push_back(v[i]);
    }
    return out;
}

vector<int> intersect(const vector<int>& a,const vector<int>& b){
    vector<int> out;
    for(size_t i=0;i<a.size();++i){
        for(size_t j=0;j<b.size();++j) if(a[i]==b[j]){
            bool already=false;
            for(size_t k=0;k<out.size();++k) if(out[k]==a[i]){ already=true; break; }
            if(!already) out.push_back(a[i]);
            break;
        }
    }
    return out;
}

int main(){
    cout<<"Task 1-4 demo"<<"\n"<<"\n";
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Original:\n"; printMat(m);
    addColumn(m,1,0);
    cout<<"After add column at pos 1:\n"; printMat(m);
    removeColumn(m,2);
    cout<<"After remove column at pos 2:\n"; printMat(m);
    cyclicShiftRowsCols(m,1,2);
    cout<<"After cyclic shift rows=1 cols=2:\n"; printMat(m);
    vector<vector<int>> t = transpose(m);
    cout<<"Transpose:\n"; printMat(t);

    cout<<"Task 5 demo (phonebook)"<<"\n"<<"\n";
    vector<string> names = {"Ivan","Olena","Petro"};
    vector<string> phones = {"+380501234567","+380671112233","+380631234000"};
    for(size_t i=0;i<names.size();++i) cout<<names[i]<<" : "<<phones[i]<<"\n";
    cout<<"\nSearch by name 'Olena':\n";
    for(size_t i=0;i<names.size();++i) if(names[i]=="Olena") cout<<phones[i]<<"\n";
    cout<<"Search by phone '+380631234000':\n";
    for(size_t i=0;i<phones.size();++i) if(phones[i]=="+380631234000") cout<<names[i]<<"\n";

    cout<<"\nTask 6 demo (sort 5 surnames)"<<"\n"<<"\n";
    vector<string> s = {"Ivanov","Petrov","Sidorov","Abramov","Bondar"};
    for(size_t i=0;i<s.size();++i) cout<<s[i]<<" "; cout<<"\n";
    for(size_t i=0;i<s.size();++i){
        size_t min=i;
        for(size_t j=i+1;j<s.size();++j) if(s[j]<s[min]) min=j;
        if(min!=i) { string tmp=s[i]; s[i]=s[min]; s[min]=tmp; }
    }
    cout<<"Sorted:\n";
    for(size_t i=0;i<s.size();++i) cout<<s[i]<<" "; cout<<"\n\n";

    cout<<"Task 7 demo"<<"\n\n";
    vector<vector<int>> A = {{1,2,3},{-1,4,5}};
    vector<vector<int>> B = {{2,3,6},{-2,7,8}};
    vector<vector<int>> C = {{1,3,9},{-1,10,11}};
    vector<int> fA = flatten(A);
    vector<int> fB = flatten(B);
    vector<int> fC = flatten(C);
    vector<int> all;
    for(size_t i=0;i<fA.size();++i) all.push_back(fA[i]);
    for(size_t i=0;i<fB.size();++i) all.push_back(fB[i]);
    for(size_t i=0;i<fC.size();++i) all.push_back(fC[i]);
    cout<<"All values (with repeats):\n";
    for(size_t i=0;i<all.size();++i) cout<<all[i]<<" "; cout<<"\n\n";
    vector<int> uniqueAll = uniq(all);
    cout<<"Unique values (no repeats):\n";
    for(size_t i=0;i<uniqueAll.size();++i) cout<<uniqueAll[i]<<" "; cout<<"\n\n";
    vector<int> commonABC = intersect(fA,fB);
    commonABC = intersect(commonABC,fC);
    cout<<"Common to A,B,C:\n";
    for(size_t i=0;i<commonABC.size();++i) cout<<commonABC[i]<<" "; cout<<"\n\n";
    vector<int> commonAC = intersect(fA,fC);
    cout<<"Common to A and C:\n";
    for(size_t i=0;i<commonAC.size();++i) cout<<commonAC[i]<<" "; cout<<"\n\n";
    vector<int> negs;
    for(size_t i=0;i<all.size();++i) if(all[i]<0){
        bool found=false;
        for(size_t j=0;j<negs.size();++j) if(negs[j]==all[i]){ found=true; break; }
        if(!found) negs.push_back(all[i]);
    }
    cout<<"Negative values without repeats:\n";
    for(size_t i=0;i<negs.size();++i) cout<<negs[i]<<" "; cout<<"\n";

    return 0;
}
