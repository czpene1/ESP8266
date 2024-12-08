# ESP8266
Electronic projects using ESP8266

## SSH Authentication

Prioritize SSH keys over Https authentication.

!!! Use the alias from SSH config

```
# Configure remote repository

git remote set-url origin git@<ssh config alias>:<organisation>/ESP8266.git

git remote set-url origin git@github-czpene1:czpene1/ESP8266.git

git remote -v
origin  git@github-czpene1:czpene1/ESP8266.git (fetch)
origin  git@github-czpene1:czpene1/ESP8266.git (push)
```

### SSH Config

```
# Default github account
Host github.com
  HostName github.com
  User git
  IdentityFile ~/.ssh/id_ed25519_github
  IdentitiesOnly yes
  ControlMaster auto
  ControlPersist 5m
# Other github account: germanium-git
Host github-germanium-git
  HostName github.com
  User git
  IdentityFile ~/.ssh/id_ed25519_github
  IdentitiesOnly yes
# Other github account: czpene1
Host github-czpene1
  HostName github.com
  User git
  IdentityFile ~/.ssh/id_ed25519_czpene1
  IdentitiesOnly yes
```

### Test SSH authentication

Use the name of the alias to connect to the remote repository

```
ssh -vT github-czpene1
```
