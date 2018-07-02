namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(qs: Qubit[]): () {
        body {
            let length = Length(qs);
            H(qs[0]);
            for(i in 1..length-1) {
                CNOT(qs[i-1], qs[i]);
            }
        }
    }
}
