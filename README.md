# Flow

**NEWS FLASH - music:play now works on Windows**

## Installation

Open the command console on Windows—or Terminal on macOS X, if you’re over 50 and still remember these things exist.

Grab the Flow binary directly using `curl`:

```
curl https://raw.githubusercontent.com/eliotmuirgrid/flow/master/flow.com --output flow.com
```

Don’t panic if Microsoft says it’s a virus threat. They say that about anything interesting.

Now, execute the binary:

```
> flow
Please use a supported command:
   function:lua:create
   function:lua:c:create
   edit
   function:lua:c:helper:create
   music:play
   lib:regenerate
   function:delete
   prefix:move
   clean
   function:c:create
   build
```

If you try `flow music:play "Cold Play"`, and if you own and have a Spotify account it should bring up Cold Play. It took an impressive amount of engineering effort to achieve what I admit is a very modest deliverable.

Thank goodness I don't have a boss to explain why this was worth it.

But in the process I can now generate a lot of tedious boiler plate in terms of creating and registering
Lua functions auto-magically(ish)

See [LIBregister](https://github.com/eliotmuirgrid/flow/blob/master/guts/source/LIB/LIBregister.cpp).  I don't
about you but I was never that excited about having to maintain all that s**t by hand.  It's definitely better
to have a computer generate this stuff for you.

This will pay off later when I actually start focusing on commercially useful problems.  I admit music:play isn't
exactly the 'killer app' although I put a lot of work into making it easier to write...

## Notes and Motivation

Alright, honesty time: So next target is cleaning up my website with broken links and re moving some of the references to social issues that I like to discuss but most of my customers would rather I didn't.

If you’re feeling adventurous, you can dive into the [repository](https://github.com/eliotmuirgrid/flow/guts/source/) to peek at the code and other exciting (read: “boring”) details. Most people won’t, but hey—maybe you’re not “most people”!

Spam is a real problem for everyone. Actually, I was wrong. Some people are very smart and didn’t share their email addresses. I was less so. If Flow helps even a little, maybe I’ll finally create something my friends are excited to share—definitely more interesting than another chat about “interoperability” and “integration.”

If this works for me, I’ll tell everyone about it. Who knows—maybe you will too.

