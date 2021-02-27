package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>Nodes.
 * 2. The number of edges is <name>Edges.
 * 3. An edge exists between <name>From[i] to <name>To[i].
 *
 */*
 */
func findShortest(graphNodes int32, graphFrom []int32, graphTo []int32, ids []int64, val int32) int32 {
    // solve here

}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 1024 * 1024)

    graphNodesEdges := strings.Split(readLine(reader), " ")
    graphNodes, err := strconv.ParseInt(graphNodesEdges[0], 10, 64)
    checkError(err)

    graphEdges, err := strconv.ParseInt(graphNodesEdges[1], 10, 64)
    checkError(err)

    var graphFrom, graphTo []int32
    for i := 0; i < int(graphEdges); i++ {
        edgeFromToWeight := strings.Split(readLine(reader), " ")
        edgeFrom, err := strconv.ParseInt(edgeFromToWeight[0], 10, 64)
        checkError(err)

        edgeTo, err := strconv.ParseInt(edgeFromToWeight[1], 10, 64)
        checkError(err)

        graphFrom = append(graphFrom, int32(edgeFrom))
        graphTo = append(graphTo, int32(edgeTo))
    }

    idsTemp := strings.Split(readLine(reader), " ")

    var ids []int64

    for i := 0; i < int(graph_nodes); i++ {
        idsItem, err := strconv.ParseInt(idsTemp[i], 10, 64)
        checkError(err)
        ids = append(ids, idsItem)
    }

    valTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    val := int32(valTemp)

    ans := findShortest(int32(graphNodes), graphFrom, graphTo, ids, val)

    fmt.Fprintf(writer, "%d\n", ans)

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
