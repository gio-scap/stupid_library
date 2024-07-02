# Create Documentation 

we need to add some doc string ``` /**/ ```, which can be autocompleted
using the Doxygen Documentation extentions. 
**Explain how to use the library in header**

1. create a doxygen configuration
    ```shell
    doxygen -g
    ```
    or use some template. Place it inside docs/
2. call ``` doxygen ``` to generate the html docs

## Nice looking doxygen: Doxygen Awesome
https://jothepro.github.io/doxygen-awesome-css

copy all the file inside the repo docs to reuse this template.
- color can be changed inside 'doxygen-custom/custom-alternatice.css'
- update the link of the github icon inside doxygen-custom/header.html

## automatically build documentation and post on github pages

- this require the repo to be public, or to have a pro github account
- use the github action in the ./github/workflow/Documentations
- create a branch named 'gh-pages'
- use this settings for the repo:

![settings repo pages](docs/img/repo_settings.png)

- change permission to read and write on settings/actions 
