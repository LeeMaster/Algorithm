(define (factorial n)
  (lambda (n) 
    (if (= n 0) 1
      (* n factorial(- n 1)))))

(begin 
  display factorial(2)
  (newline))