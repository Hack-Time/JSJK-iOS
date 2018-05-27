//
//  DetailsController.swift
//  Demo
//
//  Created by kingcos on 2018/5/27.
//  Copyright © 2018 kingcos. All rights reserved.
//

import UIKit
import PKHUD
import Alamofire

class DetailsController: UITableViewController {
    
    @IBOutlet weak var resultContentView: UIView!
    let products = [
        "Sprite",
        "coke",
        "fanta",
        "vita-lemon",
        "yogurt",
        "milk",
        "Water-yibao",
        "Water-farmer",
        "red bull",
        "Jiadele",
        
//        2    Clothes:
        "Nike",
        "Adiddas",
        "New Balance",
        
//        3    Cosmetic:
        "Sun cream:anessa",
        "Sun cream:nivea",
        "Face cream:nivea",
        "Face cream:loreal",
        "Shampoo:qingyang",
        "Shampoo:haifeisi",
        "Shampoo:Vs",
        
//        4    electronics:
        "Mini fridge:TCL",
        "Mini fridge:media",
        "Wash machine:media",
        "Wash machine:sakura",
        "Pot:bear",
        
//        5    daily necessities:
        "Laundry:blue-moon",
        "Laundry:tide",
        "Laundry:OMO",
        "Toothbrush:oralb",
        "Toothpaste:blackman",
        "Toothpaste:galgate",
        "Roll-paper:breeze",
        "Roll-paper:heart",
        
        
//        6    stationery:
        "Pen:M&G",
        "Notebook:Deli",
        
//        7    Foods:
        "Baicaowei",
        "Liangpinpuzi",
        "Potatoes:lays",
        "Cookie:ereo",
        "Cookie:qdd",
        "Noodles:heweidao",
        "Noodles:kangsf",
        "Choco:meitz",
        "Choco:ferrero",
        "Fresh:fruit(orange/mango)/eggs/tomatoes...",
        
//        8    Books:
        "Calculus",
        "Linear-algebra",
        "Computer-network",
        "Operating-system",
        "Data-structure"

    ]
    
    var isDateSelected: Bool = false
    var isProductSelected: Bool = false
    
    var publishButtonItem: UIBarButtonItem!
    
//    @IBOutlet weak var lineChartView: AAChartView!
    var aaChartView = AAChartView()
    
    @IBOutlet weak var datePicker: UIDatePicker!
    @IBOutlet weak var dateLabel: UILabel!
    
    @IBOutlet weak var productPicker: UIPickerView!
    @IBOutlet weak var productLabel: UILabel!
    
    lazy var formatter: DateFormatter = {
        var formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd"
        return formatter
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        productPicker.dataSource = self
        productPicker.delegate = self
        
        dateLabel.isHidden = true
        productLabel.isHidden = true
        
        publishButtonItem = UIBarButtonItem(title: "提交",
                                            style: .done,
                                            target: self,
                                            action: #selector(publishButtonItemClick))
        navigationItem.rightBarButtonItems = [publishButtonItem]
        
        let chartViewWidth = resultContentView.frame.size.width
        let chartViewHeight = resultContentView.frame.size.height;
        
        aaChartView.frame = CGRect(x:0,y:0,width:chartViewWidth,height:chartViewHeight)
        // set the content height of aachartView
        // aaChartView?.contentHeight = self.view.frame.size.height
        resultContentView.addSubview(aaChartView)
    }
    
    @objc func publishButtonItemClick() {
        if dateLabel.isHidden || productLabel.isHidden {
            HUD.flash(.labeledError(title: "Error", subtitle: "日期或商品不得为空"))
        } else {
            publishButtonItem.isEnabled = false
            
            HUD.show(.label("Loading..."))
            
            guard let date = dateLabel.text,
                let product_no = products.index(of: productLabel.text!) else { return }
//            let parameters: Parameters = ["date": date,
//                                          "product_no" : product_no]
            Alamofire.request("http://192.168.3.37:8000/fetch?num=\(3)&date=\(date)&product_no=\(product_no)").responseJSON { (response) in
                DispatchQueue.main.async {
                    HUD.hide()
                    self.publishButtonItem.isEnabled = true
                }
                
                var keys = [String]()
                var values = [Int]()
                if let jsonResult = response.result.value as? [[String : String]] {
                    for json in jsonResult {
                        keys.append(json.keys.first!)
                        values.append(Int(json[json.keys.first!]!)!)
                    }
                }
                
                self.updateLineChartView(self.productLabel.text!, keys, values)
            }
        }
    }
    
    func updateLineChartView(_ name: String, _ date: [String], _ count: [Int]) {
        let aaChartModel = AAChartModel.init()
            .chartType(AAChartType.Line)//Can be any of the chart types listed under `AAChartType`.
            .animationType(AAChartAnimationType.Bounce)
            .title("预测未来该日销量")//The chart title
            .dataLabelEnabled(false) //Enable or disable the data labels. Defaults to false
            .categories(date)
            .colorsTheme(["#fe117c","#ffc069","#06caf4","#7dffc0"])
            .series([
                AASeriesElement()
                    .name(name)
                    .data(count)
                    .toDic()!])
        
        aaChartView.aa_drawChartWithChartModel(aaChartModel)
    }

}

extension DetailsController {
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 3
    }
    
    override func tableView(_ tableView: UITableView,
                            numberOfRowsInSection section: Int) -> Int {
        if section == 0 && isDateSelected {
            return 2
        } else if section == 1 && isProductSelected {
            return 2
        } else {
            return 1
        }
    }
    
    override func tableView(_ tableView: UITableView,
                            didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        if indexPath.section == 0 && indexPath.row == 0 {
            selectDate()
        }
        
        if indexPath.section == 1 && indexPath.row == 0 {
            selectProduct()
        }
    }
}

extension DetailsController: UIPickerViewDataSource, UIPickerViewDelegate {
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return products.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return products[row]
    }
}

extension DetailsController {
    func selectDate() {
        isDateSelected = !isDateSelected
        tableView.reloadData()
        
        if !isDateSelected {
            dateLabel.isHidden = false
            dateLabel.text = formatter.string(from: datePicker.date)
        } else {
            dateLabel.isHidden = true
        }
    }
    
    func selectProduct() {
        isProductSelected = !isProductSelected
        tableView.reloadData()
        
        if !isProductSelected {
            productLabel.isHidden = false
            productLabel.text = products[productPicker.selectedRow(inComponent: 0)]
        } else {
            productLabel.isHidden = true
        }
    }
}
