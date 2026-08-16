---
title: 'Screw it — at least the production artifact is editable'

---

### Screw it — at least the production artifact is editable

2026-01-19

> [!NOTE]  
> This article is AI-translated (LLM, ChatGPT 5.2) from [original Chinese version (on the same page)](#file-md). The translation is reviewed by the author.

Today I was tweaking an open-source web auto-translation browser extension \[0]. What I wanted was simple: automatically trigger translation globally on every page, and use a dedicated Profile just for browsing foreign-language sites.

Then I discovered… it doesn’t work like that. The settings let you enter an allowlist of domains to auto-trigger translation for those domains, but there’s nowhere to enable it globally. The allowlist doesn’t accept wildcards, regexes, or anything fancy either. I confirmed it in the source: the check is literally `someArray.include(...)`. Brutal.

So I dug into the code and thought about hacking it. I wondered:  could I use a UserScript, a bookmarklet, or even build another extension to trigger translation? Path one: see whether the extension exposes any public API or hook method on browser `window` object. As expected, no: everything is neatly encapsulated inside React.

Path two: imitate the extension’s internal messaging — send tab messages to the tab the way it does. Also a dead end. Chrome’s extension messaging is properly isolated: unless the target extension’s `manifest.json` explicitly allows it, a third-party extension can’t talk to it.

Path three: the extension exposes a set of “commands” meant for keyboard shortcuts, and one of them is exactly the “trigger translation” action I need. Still no way to invoke it externally. Same isolation story.

I didn’t want to pull the repo locally and build it — mental friction. And who knows what kind of build setup nonsense I’d run into.

I also didn’t want to open an issue or submit a PR. If you forced me to explain: I don’t have the patience for delayed gratification; I’m lazy; and I’m not even sure other people want this feature. Auto-triggering on *every* page could mess things up when you don’t want it. And if you make it too easy, you might encourage large-scale abuse of some public translation API. I didn’t want to go there.

So I decided: screw it, I’m taking the dirty route. At least the production artifact (.crx or .zip) is just modifiable JavaScript, not something more obscure.

I downloaded the Release packaged extension zip. Without even extracting it, I edited `content.js` inside the archive. In the sea of minified code I searched for `someArray.include`, and wrapped the surrounding condition with `(... || true)`. Saved it back into the zip, then imported that zip via Chrome’s Extensions page with Developer Mode enabled.

And… it worked. The whole thing took a few minutes.

Sure, if the extension updates later I’ll need to redo the replacement. (Why would I update, anyway? I don’t need more features.) So what? This was the only approach that was both fast and guaranteed to behave exactly how I wanted. That’s probably the real meaning of editable production artifact.

\[0] [This extension](https://github.com/chunibyocola/sc-translator-crx).
