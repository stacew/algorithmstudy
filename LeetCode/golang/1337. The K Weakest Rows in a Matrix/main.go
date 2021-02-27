import "sort"
type matIndex struct{
    index int
    numberOfSoldier int
}
func kWeakestRows(mat [][]int, k int) []int {
       
    var mi []matIndex
    for i:=0; i< len(mat); i++{
        count := 0
        for j:=0; j < len(mat[i]); j++ {
            if mat[i][j] == 1 {
                count++
            }
        }
        
        mi = append(mi, matIndex{index:i, numberOfSoldier:count})
    }
    
    
    sort.Slice(mi, func(a,b int) bool {
        if mi[a].numberOfSoldier != mi[b].numberOfSoldier{
            return mi[a].numberOfSoldier < mi[b].numberOfSoldier    
        }
        return mi[a].index < mi[b].index
    })
    
    var ret []int
    for i:=0; i <k; i++{
        ret = append(ret, mi[i].index)
    }
    
    return ret
}