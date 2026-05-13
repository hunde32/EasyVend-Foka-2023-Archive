const submit = document.querySelector('.idd');
const nextBtn = document.querySelector(".next-btn");


let orders = [];
let priceArr = [45, 20, 80];
let itemArr = ["Coca Cola", "Sun Chips", "Snickers"];
let data = [];
let newItem = {};

submit.addEventListener('click', ()=>{
    const quantity = document.querySelector('.quantity').value;
    const itemNum = document.querySelector('.item-num').value;
    let index = parseInt(itemNum)-1;
    price = priceArr[index] * parseInt(quantity);
    let orderId = Math.floor(Math.random() * 10000) + 10000;

     newItem = {
        "itemname": itemArr[index],
        "quantity": parseInt(quantity),
        "price": price,
        "phonenumber": "0913095086",
        "orderid": orderId
    }
    data.push(newItem);
    console.log(JSON.stringify(data))

       next.innerHTML = "Next"; 
    next.style.marginLeft= "180px";
    next.style.marginTop= "10px";
    next.style.position="absolute";
    next.style.display="grid";
    next.style.border = "solid blue";
    next.style.padding = "14px 40px";
});




nextBtn.addEventListener("click", (e)=>{
    e.preventDefault();
    fetch("http://localhost:3000/", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify(data)
    })
        .then((response) => {
            if (!response.ok) {
                throw new Error("Network response was not ok");
            }
           
            response.text()
        }).then((data)=>{
            alert("Order: " + newItem.itemname + "\n Quantity: " + newItem.quantity + "\n Price" + newItem.price + "\n OrderId: " + newItem.orderid)

        })
})

// document.getElementById("submite").onclick = function(){
//     next.innerHTML = "Next"; 
//     next.style.marginLeft= "180px";
//     next.style.marginTop= "10px";
//     next.style.position="absolute";
//     next.style.display="grid";
//     next.style.border = "solid blue";
//     next.style.padding = "14px 40px";
// }
