-module(simple).
-compile(export_all).


helloWorld()->
    io:format("Hello World\n").

getageGroup()->
    io:format("Enter your age in years:"),
    {ok, [Age]} = io:fread("input : ", "~d"),
    getGroup(Age).

getGroup(Age)->
    if
	Age<13->
	      io:format("just a kid!\n");
	Age<20 ->
	      io:format("unruly teenager\n");
	Age<30 ->
	      io:format("Too young to know better\n");
	Age<40 ->
	      io:format("Oh God the stress!\n");
       	Age<55 ->
	      io:format("in the prime of life\n") %;
	%true ->
	%      io:format("My bones hurt\n")
    end.

getGroup2(Age)when Age<13->
 io:format("just a kid\n");
getGroup2(Age)when Age<20->
    io:format("you cannot vote yet\n");
getGroup2(Age)when Age<30 ->
    io:format("Too young to know better\n");
getGroup2(Age)when Age<40->
    io:format("Oh God the stress!\n");
getGroup2(Age)when Age<55 ->
    io:format("in the prime of life\n");
getGroup2(_)->
    io:format("My bones hurt\n").


factorial(0)->
    1;
factorial(1)->
    1;
factorial(N) ->
    N*factorial(N-1).

