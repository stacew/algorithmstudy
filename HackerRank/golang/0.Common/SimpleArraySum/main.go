func simpleArraySum(ar []int32) int32 {
    var sum int32
    for i := 0; i < len(ar); i++ {
        sum = sum + ar[i]
    }
    return sum
}