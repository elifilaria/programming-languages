#lang eopl

(define identifier?
  (lambda (exp)
    (and (symbol? exp) (not (eq? 'lambda exp)))))

(define-datatype lc-exp lc-exp?
  (var-exp 
   (var identifier?))
  (lambda-exp
   (bound-var identifier?)
   (body lc-exp?))
  (app-exp
   (rator lc-exp?)
   (rand lc-exp?)))

(define parse
  (lambda (lc-exp)
    (cond
      ((symbol? lc-exp)(var-exp lc-exp))
      ((eq?(car lc-exp)'lambda)(lambda-exp(caadr lc-exp)(parse(caddr lc-exp))))
      (else (app-exp(parse(car lc-exp))(parse(cadr lc-exp)))))))



(display(parse '((d e)(a b))))
