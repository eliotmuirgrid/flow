function GITcloneGithub(Repo, Dest)
   ARGcheck(2, "Need <repo> <dest>", Repo, Dest);
   GITclone(GITurlGithubEliotMuirGrid(Repo), Dest);
   print("TODO check git submodule update --init --recursive");
end
