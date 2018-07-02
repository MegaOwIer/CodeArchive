namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set(q: Qubit, sta: Result): () {
        body {
            let res = M(q);
            if(res != sta) {
                X(q);
            }
        }
    }

    operation Solve(q: Qubit, sign: Int): () {
        body {
            if(sign == 1) {
                Set(q, Zero);
            } else {
                Set(q, One);
            }
            H(q);
        }
    }
}
