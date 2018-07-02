namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(qs: Qubit[], bits0: Bool[], bits1: Bool[]): Int {
        body {
            let len = Length(qs);
            for(i in 0..len-1) {
                let sta = M(qs[i]);
                if(sta == Zero && bits0[i] == true) {
                    return 1;
                }
                if(sta == One && bits0[i] == false) {
                    return 1;
                }
            }
            return 0;
        }
    }
}