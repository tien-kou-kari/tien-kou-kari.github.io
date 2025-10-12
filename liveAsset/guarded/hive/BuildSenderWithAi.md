
Please try building a "sender" HTML page for my content managing system.

The HTML is a full and standalone one, and should be as minimal as possible, without additional external JavaScript/CSS libraries/resources. The CSS styling should be minimal; keep native UserAgent style at maximum possible.

Do full implementation; do not omit or mock on the excuse of demonstration usage.

The HTML should be suitable for use on desktop and phone devices. On desktop, the content on the page should not be too wide; the width should be limited, and when the width is limited, the content should be aligned (leaning) to the left.

The page consists:

- Combobox with label: "mdPath" (The combobox should be implemented in HTML `<datalist>` element, default value: empty, preset option values: `Journal.md`, `Test.md`, `misc/$date_$time_$*.md`, `misc/$date_$time.md`, `$date_$time_$*.md`, `$date_$time.md`, `$date.md`). It means the relative path of the Markdown file to which current post is sent. Most recent values are stored in LocalStorage via JavaScript, and are shown in dropdown. Default value is: ``
- Combobox with label: "attachPath" (The combobox should be implemented in HTML `<datalist>` element, default value: empty, preset option values: 
`miscMedia/$date_$time_$#$ext`, `miscMedia/$date_$time_$*_$#$ext`, `miscMedia/$date_$time_$#_$*$ext`,  `$md_$#$ext`, `$md_$*$ext`, `$md_$*_$#$ext`, `$md_$#_$*$ext`, `$md_$#_$aorig$ext`, `miscMedia/$date_$time_$#_$aorig$ext`, `miscMedia/$date_$time_$*$ext`, `miscMedia/$date_$time$ext`). It means the relative path pattern of the attachment (media) files to be saved. Most recent values are stored in LocalStorage via JavaScript, and are shown in dropdown.
- Checkbox: "Append Mode". Means whether to append into the Markdown file, or to totally overwrite it. Checked by default.
- Dropdown box: (I advise to put to the right of the checkbox, forming two columns.) Allow user to select file saving mechanism implementation (browser filesystem API / HTTP API on https://my-server-1.com / HTTP API on http://my-server-2.com / ...), described below.
- A large textarea in which the text content of the post is written, taking most space of the page excluding the space other elements take.
- A series of attachment file upload component with description text input. Shows one file upload element and one description text input by default, and by clicking a small button shows a new pair, allowing multiple files to be uploaded.
- A relatively large "Submit" button.
- I advise that the attachment file upload/description columns and the submit botton is put into two vertical columns side by side. The adding of the attachment file upload should not change the position nor size of the submit button.
- A status bar to show "success" or "error" message to the user. Not needed to implement timed auto-hide mechanism.

The post sending logic is implemented in JavaScript, described below:

- Intepret "mdPath" and "attachPath". Replace the following placeholders: `$date` as current local date in format `yyyy-MM-dd`; `$time` as current local date in format `HH-mm-ss` (Note: DO NOT use colons; Windows doesn't accept it); `$dt` as datetime `yyyy-MM-dd_HH-mm-ss`; `$*` as a randomly generated (but consistent across one time of post) number string.
  - The following placeholders is for "attachPath" specifically: `$md` as the base file name of the Markdown path, without extension; `$aorig` as the original attachment file name without extension; `$ext` as the original attachment file's extension (containing the dot; please correctly handle the case when the file has no extension); `$#` as the sequence number of the attachment, starting from 0.
- Write the Markdown file, and place the attachment files in paths according to the input path (pattern). This step must be abstracted into an interface, with two implementations: One using browser filesystem API, one using HTTP GET/POST calls (Please design the API and implement the server in plain Node.JS without dependency). The user selects the implementation and the web server API address using above mentioned dropdown list. Note "mdPath" and "attachPath" are both relative path (pattern), and in utilizing browser filesystem API, the user should be prompted a root directory on the local machine at first time, but it should be remembered for the next times; in the HTTP server there should be a way to configure the root directory. The HTTP server should have basic authorization based on providing a correct fixed query secret token value. No file operations should be made outside of the specified root directory, please do sufficient check in the HTTP server implementation.
  - Before writing the markdown file, the markdown must be appended the reference of attachment files, each file one paragraph.
    - When an attachment is an image, it is referenced with `<img class=" class="md-attach md-attach-img"">` element wrapped in an `<a class="md-attach md-attach-img-link">` link, with `target="_blank"`, pointing to the URL of the image. the `<img>` element has maximum width 20 rem, and maximum height 40 rem. Its `title` and `alt` property filled with what the user filled in the corresponding description text input.
    - When an attachment is a video file, it is referenced with `<video control class=" class="md-attach md-attach-video"">` element, has maximum width 20 rem, and maximum height 40 rem, and has `title` and `alt` property filled with what the user filled in the corresponding description text input.
    - Otherwise, show it as an `<a class="md-attach md-attach-file-link">` link, with `target="_blank"`. Its text content shows the file base name part of the generated attachPath.
    - In all above attachment elements, the mentioned URL (href/src/etc.) should be a pure path URL (without `https://` scheme, hostname, port) generated by directly prepending the target file relative path (by path pattern) with a forward slash `/`, simply converting it into an absolute path.
  - Then write the markdown content into the target file. The handling is slightly different in two modes:
    - In append mode: Append the target file (Create if not exists) two new lines, current local datetime format as `yyyy-MM-dd HH:mm:ss`, a space, then the content of the textarea, then two newlines, then the HTML elements referencing the attachments, then a newline.
    - In overwrite mode: Write the content of textarea directly into (overwrite if already existing) the target file, then two newlines, then the HTML elements referencing the attachments.
  - Then place the uploaded attachment files according to the paths generated by "attachPath" path pattern.

Give the above HTML, and give the Node.JS server implementation.
