-module(fibonacci).
-export([fib/1]).

fib(N) when N < 2->
    1;

fib(N) ->
    fib(N-1) + fib(N-2);