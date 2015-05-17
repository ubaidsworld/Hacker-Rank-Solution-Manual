package main
import (
    "fmt"
    "bufio"
    "os"
)
/*
https://www.hackerrank.com/challenges/pangrams
*/
func main(){
    reader := bufio.NewReader(os.Stdin)
    text, _ := reader.ReadString('\n')
    
    var ref map[rune]int = make(map[rune]int)
    count := 0
    
    ll := rune('a')
    lr := rune('z')
    ul := rune('A')
    ur := rune('Z')
    diff := ll - ul
    for _,c := range text {
        if c >= ll && c <= lr {
            _,ok := ref[c]
            if !ok {
                ref[c] = 1
                count++
            }
            if count == 26{
                break
            }
        } else if c >= ul && c <= ur {
            c += diff
            _,ok := ref[c]
            if !ok {
                ref[c] = 1
                count++
            }
            if count == 26{
                break
            }
        }
    }
    
    if count == 26 {
        fmt.Println("pangram")
    } else {
        fmt.Println("not pangram")
    }
}
