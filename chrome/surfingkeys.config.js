// Reminders:
//  - ;s to toggle the PDF viwer
//  - alt-s to toggle surfingkeys for a given website

settings.modeAfterYank = "Normal"

settings.blacklistPattern = /.*thetypingcat/i

// Unmap useless search bindings
unmap("sd") // duckduckgo
unmap("sb") // baidu
unmap("sw") // wikipedia
unmap("ss") // stackoverflow
unmap("sh") // github
unmap("sy") // youtube

// Remap j and h to work better with Colemak-DHm
// map("h", "j");
// map("j", "h");

// Remap history back/foward
map("l", "S")
map("u", "D")

settings.tabsThreshold = 0
settings.tabsMRUOrder = true

// Use t for new tab
map("t", "on") 

// Tab navigation
map("<f7>", "R")
map("<f10>", "E")

// Optimize hint characters for Colemak-DHm
Hints.characters = "stradfpwgenihouylm,./"


// Styling
Hints.style("border: solid 3px transparent; color: #fff; background: initial; background-color: #ff4700;")

settings.theme = `
:root {
  --font: Menlo, sans-serif;
}

.sk_theme {
  font-family: var(--font);
  color: #212428;
}

#sk_omnibar {
  box-shadow: 0px 1px 5px 0px rgb(177 177 177 / 80%);
}

.sk_omnibar_middle #sk_omnibarSearchArea {
  margin: 9px;
  padding: 5px 5px 5px 0;

  background-color: #f5f5f5;

  border-bottom: none;
  border-radius: 4px;
}

.sk_theme input {
  font-size: 18px;
  color: #424a54; 
}

#sk_omnibarSearchArea .prompt {
  display: none;
}

#sk_omnibarSearchArea .resultPage {
  display: none;
}

#sk_omnibarSearchResult .url {
  display: none;
}

#sk_omnibarSearchResult ul li {
  padding: 9px 9px;
}

#sk_omnibarSearchResult ul li:last-child {
  padding: 9px 0 9px 9px;
}
`;
