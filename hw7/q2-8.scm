(define empty-env
  (lambda () '()))

(test-equal? "creates empty environment" (empty-env) '())

(define empty-env?
  (lambda (env)
    (null? env)))

(test-true "empty env is empty" (empty-env? (empty-env)))
(test-false "env with bound variable is not empty" (empty-env? '((x . 3))))

(define extend-env
  (lambda (var val env)
    (cons (cons var val) env)))

(define report-no-binding-found
  (lambda (search-var)
    (eopl:error 'apply-env "No binding for ~s" search-var)))

(define apply-env
  (lambda (env search)
    (cond
      [(null? env) (report-no-binding-found search)]
      [(eqv? (car (car env)) search) (cdr (car env))]
      [else (apply-env (cdr env) search)])))
