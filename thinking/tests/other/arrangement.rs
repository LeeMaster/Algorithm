use algo::other::arrangement::*;

#[test]
fn permute() {
    let array = vec![1, 2, 3];
    let result = Permute::permute(array);
    assert_eq!(
        result,
        [
            [1, 2, 3],
            [1, 3, 2],
            [2, 1, 3],
            [2, 3, 1],
            [3, 1, 2],
            [3, 2, 1]
        ]
    );
}
