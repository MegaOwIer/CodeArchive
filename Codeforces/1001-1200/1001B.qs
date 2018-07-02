namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set(q: Qubit, init: Result): () {
        body {
            let res = M(q);
            if(res != init) {
                X(q);
            }
        }
    }

    operation Solve(qs: Qubit[], index: Int): () {
        body {
            if(index >= 2) {
                Set(qs[1], One);
            }
            if(index % 2 == 1) {
                Set(qs[0], One);
            }
            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
    }
}
