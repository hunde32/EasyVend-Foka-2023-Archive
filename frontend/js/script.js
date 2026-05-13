var sidemenu = document.getElementById("sidemenu");
let readmore = 1; 

document.getElementById("open").onclick = function(){
  sidemenu.style.right = "-10px"
}
document.getElementById("close").onclick = function(){
  sidemenu.style.right = "-200px"
}

document.getElementById("readmore").onclick = function(){
  document.getElementById("read").innerHTML = "Welcome to Easy Vend! At Easy Vend, we are not just an online vending machine ordering platform, but also a team of passionate innovators who design and develop our own vending machines. Our mission is to provide a seamless and convenient experience for our customers, from ordering online to enjoying your favorite snacks and beverages.With our expertise in vending machine development, we have created state-of-the-art machines that are designed to enhance your snacking experience. Our machines are equipped with advanced technology and user-friendly interfaces, making it easy for you to select and order your desired items. We take pride in the quality and reliability of our vending machines, ensuring that they are stocked with a wide variety of products to cater to all tastes and preferences. Easy Vend goes beyond just offering a platform for online ordering. We have integrated our vending machines with our website, allowing you to conveniently browse through our inventory, place your order, and make secure online payments. Whether you're at home, in the office, or on the go, you can easily access our website and enjoy the convenience of having your favorite snacks and beverages just a few clicks away.Customer satisfaction is at the core of our business. Our dedicated team at Easy Vend is committed to providing exceptional service and support. We are always available to assist you with any inquiries or concerns you may have. Your feedback is invaluable to us as we continuously strive to improve our products and services to meet your needs. Thank you for choosing Easy Vend for all your vending machine needs. We are excited to serve you and provide you with a seamless and enjoyable snacking experience."
}



