def removeRedundantCharacter(li) -> list:
    l,r = 0,len(li) - 1
    while l <= r:
        cur = li[l]
        cur.strip()
        if len(cur) == 0:
            l += 1
        else :
            break
    while r >= l:
        cur = li[r]
        cur.strip()
        if len(cur) == 0:
            r -= 1
        else :
            break
    return [li[i] for i in range(l,r + 1)]


def testCompare(author_ans,competitor_ans) -> bool:
    with open(author_ans,'r') as test_out, open(competitor_ans,'r') as test_ans:
        l = test_out.readlines()
        r = test_ans.readlines()
        l = removeRedundantCharacter(l)
        r = removeRedundantCharacter(r)
        if len(l) != len(r):
            print("> not same\n")
            return False
        else:
            cur_line = 1
            for x,y in zip(l,r):
                x = x.strip()
                y = y.strip()
                if x != y:
                    print("> different was found on line {0}\n".format(cur_line))
                    print("> expected output: {0}\n".format(x))
                    print("> actual output: {0}\n".format(y))
                    return False
                else :
                    cur_line += 1
    return True


def doChecker(checker_process,checker_name,inp,out,ans) -> bool:
    ok = checker_process.run(checker_name,tuple([[inp,out,ans]]))
    return True if ok == 0 else False
    

