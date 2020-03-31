; x * x
(define (square x) (* x x))

(define (sqrt x)
  ; if |guess - x| < 0.001 return true
  (define (good_enough guess x) (< (abs (- (square guess) x)) 0.001))
  ; average of the x and y
  (define (average x y) (/ (+ x y) 2))
  ; imporve guess to new guess  
  (define (imporve guess x) (average guess (/ x guess)))
  ; this is a loop procdure 
  (define (sqrt_iter guess x)
    (if good_enough guess x)
      guess 
      (sqrt_iter (imporve guess x) x)
  )
  ; caller
  (sqrt_iter 1.0 x)
)