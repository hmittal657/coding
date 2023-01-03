// https://leetcode.com/problems/count-vowels-permutation

class Solution {
public:

#define ll long long

    ll MOD = 1000000007L;

    int countVowelPermutation(int n) {

        ll preva = 1;
        ll preve = 1;
        ll previ = 1;
        ll prevo = 1;
        ll prevu = 1;

        ll ans = 5;

        for (int i = 2; i <= n ; i++) {
            ll cura = preve + previ + prevu;
            cura = cura % MOD;
            ll cure = preva + previ;
            cure = cure % MOD;
            ll curi = preve + prevo;
            curi = curi % MOD;
            ll curo = previ;
            curo = curo % MOD;
            ll curu = previ + prevo;
            curu = curu % MOD;


            ans = (cura + cure + curi + curo + curu);
            if (ans > MOD) {
                ans = ans % MOD;
            }
            preva = cura;
            preve = cure;
            previ = curi;
            prevu = curu;
            prevo = curo;
        }

        return (int)(ans % MOD);
    }
};