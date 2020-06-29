func camelcase(s string) int32 {
    if len(s) == 0{
        return 0
    }

    var count int32 = 1
    for i := 1; i < len(s); i++ {
        if s[i] <= 'Z' {
            count++
        }
    }
    return count
}