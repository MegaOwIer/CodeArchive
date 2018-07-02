namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(N: Int, Uf: ((Qubit[], Qubit) => ())): Bool {
        body {
            mutable ans = new Result[N];
            using(qs = Qubit[N + 1]) {
                X(qs[N]);
                for(i in 0..N) {
                    H(qs[i]);
                }
                Uf(qs[0..N-1], qs[N]);
                for(i in 0..N - 1) {
                    H(qs[i]);
                }
                for(i in 0..(N - 1)) {
                    set ans[i] = M(qs[i]);
                }
                ResetAll(qs);							
            }
            return ForAll(IsResultZero, ans);
        }
    }
}