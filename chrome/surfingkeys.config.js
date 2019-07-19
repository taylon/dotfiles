settings.blacklistPattern = /.*thetypingcat/i;

// Unmap useless search bindings
unmap("sd");
unmap("sb");
unmap("sw");
unmap("ss");

// Remap history back/foward
map("l", "S");
map("u", "D");

Hints.characters = "stradfpwgenihouylm,./";

settings.theme = `
.sk_theme {
    font-family: Operator Mono SSm Book, sans-serif;
    font-size: 18px;
    background: #24272e;
    color: #abb2bf;
}

.sk_theme tbody {
    color: #fff;
}

.sk_theme input {
    color: #d0d0d0;
}

.sk_theme .url {
    color: #61afef;
}

.sk_theme .annotation {
    color: #56b6c2;
}

.sk_theme .omnibar_highlight {
    color: #528bff;
}

.sk_theme .omnibar_timestamp {
    color: #e5c07b;
}

.sk_theme .omnibar_visitcount {
    color: #98c379;
}

.sk_theme #sk_omnibarSearchResult>ul>li:nth-child(odd) {
    background: #303030;
}

.sk_theme #sk_omnibarSearchResult>ul>li.focused {
    background: #3e4452;
}

#sk_status, #sk_find {
    font-size: 20pt;
}`;
