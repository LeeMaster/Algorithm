; fabonacci recurive
(define (fabonacci_rec n) 
  (cond (
    (= n 0) 0) 
    ((= n 1) 1)
    (else (+ (fabonacci_rec (- n 1)) (fabonacci_rec (- n 2))))))

; fabonacci loop 
; DFS like algo now the number is n and a = pos(1) value b = pos(0) value 
; should carry the depth named count and let a = k - 1 let b = k -2 
; it's same like DP algotithm right use the const memeory sapce 
(define (fabonacci_loop n)
  (define (iter a b count)
    (if (= count 0)
      b
      (iter (+ a b) a (- count 1))))
  (iter 1 0 n))
