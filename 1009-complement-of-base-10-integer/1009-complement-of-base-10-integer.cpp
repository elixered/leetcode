class Solution {
public:

   int bitwiseComplement(int N) {
    int comp = 1;
    while (comp < N) 
        comp = (comp << 1) | 1;
    return N ^ comp;
}
};