![](https://img.shields.io/github/languages/code-size/rpdjf/betterft?color=5BCFFF)

![](https://img.shields.io/badge/windows%20terminal-4D4D4D?style=for-the-badge&logo=windows%20terminal&logoColor=white)
![](https://img.shields.io/badge/WSL-0a97f5?style=for-the-badge&logo=linux&logoColor=white)

![](	https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white)

# Betterft 🚀

## What's Up?

Betterft is like the cool cousin of the C library "libft." We spiced things up a bit, but don't worry, it's still the same old library you know. The main twist? We swapped out `malloc` for the slick `galloc` function, and it all gets stored in a list we call the Garbage Collector. 🗑️

## Garbage Collector, Keeping it Tidy 💽

So, the Garbage Collector is like the guardian of our memory party. Need to clean up the whole place? Hit up `cleargarbage`. Want to be more selective? Use `gfree` to free a specific address and kick it off the list.

### Mixing it Up 🤘

If you're doing memory business without betterft (no hard feelings, seriously), there's `addgarbage` to manually add stuff to the Garbage Collector's list. But honestly, all betterft allocations are already on the VIP list.

## Warning! 🚨

Dive into the source file for the full lowdown on how to vibe with Betterft. And don't forget to enjoy the code! 😎✌️

Now go, code a better life with Betterft! 🚀✨
